#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <libgit2/libgit2.h>

namespace fs = std::filesystem;

void clone_repo(const std::string& repo_url, const std::string& clone_dir) {
    git_libgit2_init();
    git_repository* repo = nullptr;
    git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;

    int error = git_clone(&repo, repo_url.c_str(), clone_dir.c_str(), &clone_opts);
    if (error != 0) {
        const git_error* e = giterr_last();
        std::cerr << "Error " << error << ": " << (e && e->message ? e->message : "Unknown error") << std::endl;
        git_libgit2_shutdown();
        exit(EXIT_FAILURE);
    }
    git_repository_free(repo);
    git_libgit2_shutdown();
}

void run_config_script(const fs::path& package_dir) {
    fs::path config_file = package_dir / "config.flash";
    if (!fs::exists(config_file)) {
        std::cerr << "Config file not found: " << config_file << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ifstream config(config_file);
    std::string line;
    std::string exec_command;

    while (std::getline(config, line)) {
        if (line.find("exec=") == 0) {
            exec_command = line.substr(5);
            break;
        }
    }

    if (exec_command.empty()) {
        std::cerr << "No exec command found in config file." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Running install command: " << exec_command << std::endl;
    int result = std::system(exec_command.c_str());
    if (result != 0) {
        std::cerr << "Install command failed with error code: " << result << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3 || std::string(argv[1]) != "-S") {
        std::cerr << "Usage: " << argv[0] << " -S <github_user>/<repo>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string github_user_repo = argv[2];
    size_t slash_pos = github_user_repo.find('/');
    if (slash_pos == std::string::npos) {
        std::cerr << "Invalid repository format. Use <github_user>/<repo>." << std::endl;
        return EXIT_FAILURE;
    }

    std::string github_user = github_user_repo.substr(0, slash_pos);
    std::string repo = github_user_repo.substr(slash_pos + 1);
    std::string repo_url = "https://github.com/" + github_user + "/" + repo;
    fs::path clone_dir = fs::path(getenv("HOME")) / ".flash" / "packages" / repo;

    clone_repo(repo_url, clone_dir.string());
    run_config_script(clone_dir);

    std::cout << "Package " << repo << " installed successfully." << std::endl;
    return EXIT_SUCCESS;
}
