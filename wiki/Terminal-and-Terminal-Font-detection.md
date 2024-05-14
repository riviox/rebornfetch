**[#252](https://github.com/dylanaraps/neofetch/pull/252)** added support for displaying the terminal emulator in use as well as the font the terminal emulator is currently using.

## Terminal Detection

#### Mac OS X

Terminal detection works by checking the value of `$TERM_PROGRAM`.

#### All other OS

Terminal detection works by recursively checking parent processes until the result
isn't `$SHELL`, `*sh`, `screen` or `tmux`.

This method of detection doesn't work with `tmux` as the parent processes aren't
the current shell or the terminal emulator.

## Font Detection

Font detection works by parsing the terminal emulator's config file.

#### Funtion Support

| Terminal Emulator | Config Type | Font Detection |
| ----------------- | ----------- | -------------- |
| Alacritty         | Global      | Yes            |
| Deepin-terminal   | Global      | Yes            |
| Gnome-terminal    | Profile     | No             |
| iTerm2            | Profile     | No             |
| HyperTerm         | Global      | Yes            |
| Konsole           | Profile     | Yes            |
| Mintty            | Global      | Yes            |
| Pantheon          | Global      | Yes            |
| Sakura            | Global      | Yes            |
| st                | None        | No             |
| Terminal.app      | N/A         | Yes            |
| Terminator        | Profile     | No             |
| Terminology       | Profile     | No             |
| Termite           | Global      | Yes            |
| URxvt             | N/A         | Yes            |
| Xfce4-terminal    | Global      | Yes            |
| Xterm             | N/A         | Yes            |

**Profile**: The font info is split based on profiles.
**N/A**: A command is used (`xrdb` / `osascript`) to get the font.
