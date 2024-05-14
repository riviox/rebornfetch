This wiki page will guide you through getting neofetch working on your system.

The first and most universal way of installing neofetch is by downloading/cloning
the latest release and running the Makefile.

# Table of Contents

<!-- vim-markdown-toc GFM -->
* [Universal Install](#universal-install)
    * [Latest Release](#latest-release)
    * [Latest Git Master (Bleeding Edge)](#latest-git-master-bleeding-edge)
* [OS/Distro Packages](#osdistro-packages)
    * [Alpine Linux](#alpine-linux)
        * [Alpine Linux v3.8 and up](#alpine-linux-v38-and-up)
    * [Android (Termux)](#android-termux)
    * [Arch](#arch)
    * [BunsenLabs](#bunsenlabs)
    * [CRUX](#crux)
    * [Debian](#debian)
        * [Stretch / Sid (Unstable)](#stretch--sid-unstable)
    * [Fedora / RHEL / CentOS / Mageia / OpenMandriva](#fedora--rhel--centos--mageia--openmandriva)
    * [FreeBSD](#freebsd)
    * [Gentoo / Funtoo](#gentoo--funtoo)
    * [GoboLinux](#gobolinux)
    * [iOS/iPadOS](#iosipados)
    * [macOS (Homebrew)](#macos-homebrew)
    * [NixOS](#nixos)
    * [Slackware](#slackware)
    * [Solus](#solus)
    * [Ubuntu](#ubuntu)
        * [Ubuntu 17.04 and up](#ubuntu-1704-and-up)
        * [Ubuntu 16.10 and below](#ubuntu-1610-and-below)
    * [Void Linux](#void-linux)
    * [openSUSE](#openSUSE-Leap-or-Tumbleweed)
    * [Windows](#windows)

<!-- vim-markdown-toc -->


# Universal Install

## Latest Release

1. Download the latest release.
    - https://github.com/dylanaraps/neofetch/releases/latest
2. Run `make install` inside the script directory to install the script.
    - **MacOS**: `make PREFIX=/usr/local install`
    - **Haiku**: `make PREFIX=/boot/home/config/non-packaged install`
    - **OpenIndiana**: `gmake install`
    - **MinGW/MSys**: `make -i install`
    - **NOTE**: You may have to run this as root.

## Latest Git Master (Bleeding Edge)

1. Git clone the repo.
    - `git clone https://github.com/dylanaraps/neofetch`
2. Change working directory to `neofetch`.
    - `cd neofetch`
3. Install neofetch using the Makefile.
    - `make install`
    - **MacOS**: `make PREFIX=/usr/local install`
    - **Haiku**: `make PREFIX=/boot/home/config/non-packaged install`
    - **OpenIndiana**: `gmake install`
    - **MinGW/MSys**: `make -i install`
    - **NOTE**: You may have to run this as root.

**NOTE:** Neofetch can be uninstalled easily using `make uninstall`. This removes
all of files from your system.

**NOTE:** You can run neofetch from any folder on your system, all the makefile
does is move the files to a "sane" location. The Makefile is optional.

# OS/Distro Packages

This section lists neofetch packages that have been made for specific OS/Distros.


## Alpine Linux

### Alpine Linux v3.8 and up

1. Update repositories
    - `apk update`
2. Install the package
    - `apk add neofetch`


## Android (Termux)

Neofetch is in Termux's default repos.

1. Update repositories
    - `pkg update`
2. Install the package
    - `pkg install neofetch`


## Arch

Neofetch is available in the official repos.

- Install the package
    - `pacman -S neofetch`


## BunsenLabs

Neofetch is available in the official repos.

1. Update repositories
    - `sudo apt-get update`
2. Install the package
    - `sudo apt-get install neofetch`


## CRUX

1. Install git and the git ports(8) driver
    - `sudo prt-get depinst git`
2. Add the `6c36-git` repository
    - `sudo wget -O /etc/ports/6c37-git.git "https://raw.githubusercontent.com/6c37/cross/master/git-driver/6c37-git.git"`
3. Sync the repos
    - `sudo ports -u`
4. Add the repo to /etc/prt-get.conf with your text editor of choice
    - `prtdir /usr/ports/6c37-git`
5. Install the package
    - `sudo prt-get depinst neofetch`

Or alternatively use the [port](https://raw.githubusercontent.com/6c37/crux-ports-git/3.2/neofetch/Pkgfile):

1. Download port
    - `wget -O ~/work/neofetch/Pkgfile "https://raw.githubusercontent.com/6c37/crux-ports-git/3.2/neofetch/Pkgfile"`
2. Build the package
    - `fakeroot pkgmk -d`
3. Install the package
    - `sudo pkgadd neofetch#git-*.pkg.tar.gz`


## Debian

### Stretch / Sid (Unstable)

Neofetch is in Debian Stretch/Sid's official repositories.

1. Update repositories
    - `sudo apt-get update`
2. Install the package
    - `sudo apt-get install neofetch`

NOTE: Debian `stretch` repo only contains version 2.0.2.

NOTE2: The third party bintray repo has been deprecated, if you want to stay up to date with neofetch on Debian stable, then you need to manually install newer packages from unstable or download neofetch directly from git repository since it's contained in single file.


## Fedora / RHEL / CentOS / Mageia / OpenMandriva

Neofetch is in Fedora's official repositories starting from Fedora 27.

- `sudo dnf install neofetch`

Alternatively, you can use a third-party repo:

**NOTE**: If you are using RHEL/CentOS, change `dnf` into `yum`.

1. Make sure you have installed `dnf-plugins-core`
2. Enable COPR repository
    - `sudo dnf copr enable konimex/neofetch`
3. Install the package
    - `sudo dnf install neofetch`

Alternatively:

1. If you're using RHEL/CentOS, make sure you have installed `epel-release`
2. Fetch the repo file
  - `curl -o /etc/yum.repos.d/konimex-neofetch-epel-7.repo https://copr.fedorainfracloud.org/coprs/konimex/neofetch/repo/epel-7/konimex-neofetch-epel-7.repo`
    - **NOTE**: If you are using Fedora, change `epel-7` to `fedora-23`
                or your Fedora version respectively. However if you are
                using RHEL/CentOS 6, change it to `epel-6`.
3. Install the package
    - `sudo dnf install neofetch`

## FreeBSD

Install it from the official pkg repository:

- `sudo pkg install neofetch`

## Gentoo / Funtoo

You can install `app-misc/neofetch` from Gentoo/Funtoo's official repositories.

To install the git version of neofetch, use `=app-misc/neofetch-9999` instead.


## GoboLinux

Install it with the official recipe.

- `sudo Compile neofetch`

## iOS/iPadOS

### Jailbreaks with the Procursus Repo

1. Just install `neofetch` from your perfered package manager e.g. Sileo

### Jailbreaks without the Procursus Repo

1. Add this repo to your package manager e.g. Cydia
    - `https://repo.packix.com/`
2. Install `NeoFetch-iOS` from your package manager 

**NOTE**: The package on Packix isn’t the official release, and seems offline by 2020-04-14. Device MUST be jailbroken!  

## macOS (Homebrew)

1. Install `neofetch` with Homebrew
    - `brew install neofetch`

## NixOS

Install it from the official repositories

- `sudo nix-env -i neofetch`


## Slackware

Download the files from [SlackBuilds](https://slackbuilds.org/repository/14.2/desktop/neofetch/) and follow [their instructions](https://slackbuilds.org/howto/).


## Solus

You can find neofetch in software center under System Software > System Utilities or type `sudo eopkg it neofetch`.


## Ubuntu

### Ubuntu 17.04 and up

Install it from the official repositories.

1. Update repositories
    - `sudo apt update`
2. Install the package
    - `sudo apt install neofetch`

NOTE: The third party PPA has been deprecated and could be deleted anytime without notice.

## Void Linux

Install it from the official repositories

- `sudo xbps-install -S neofetch`

## openSUSE Leap or Tumbleweed

Install it from the official repositories.

- `sudo zypper install neofetch`

## Windows

Install it from the [Scoop](https://github.com/lukesampson/scoop).

- `scoop install neofetch`







