This page lists the programs/dependencies Neofetch needs to run.

**NOTE:** Neofetch only requires **BASH**, the rest of the dependencies are entirely optional and only enable additional features and functionality.

## Table of Contents

<!-- vim-markdown-toc GFM -->
* [Required dependencies:](#required-dependencies)
* [Image mode dependencies:](#image-mode-dependencies)
* [Optional dependencies:](#optional-dependencies)
    * [Wallpaper](#wallpaper)
    * [Disk](#disk)
    * [Song](#song)
    * [Desktop Environment and Window Manager](#desktop-environment-and-window-manager)
    * [Resolution](#resolution)
    * [Public IP](#public-ip)
    * [GPU](#gpu)
* [iOS Dependencies](#ios-dependencies)
* [Android Dependencies](#android-dependencies)

<!-- vim-markdown-toc -->


## Required dependencies:

- `bash 3.2+`
    - Alpine Linux: You also need `ncurses`.


## Image mode dependencies:

These dependencies are required for image mode to work.

- Displaying images: 
    - `w3m-img` \[1\]
    - `iTerm2` \[2\]
    - `Terminology` \[2\]
    - `kitty` \[2\]
    - `libsixel`
    - `termpix`
    - `pixterm`
    - `catimg`
    - `jp2a`
    - `caca-utils` or `libcaca`.
- Thumbnail creation: `imagemagick`
- Window size: A terminal emulator that supports `\033[14t` \[3\] or `xdotool` or `xwininfo + xprop` or `xwininfo + xdpyinfo`

\[1\] `w3m-img` is sometimes bundled together with `w3m`.

\[2\] Image support is built into Terminology, iTerm2 and kitty, and doesn't require w3m-img.

\[3\] See this wiki page for more information: [Images in the terminal](https://github.com/dylanaraps/neofetch/wiki/Images-in-the-terminal)


## Optional dependencies:


### Wallpaper

**Any OS running an X Server**

- Desktop Environment: `XFCE`, `GNOME`, `Cinnamon` or `MATE`
- Universal: `feh`, `nitrogen` or `gsettings`

**Windows and macOS**

- No additional dependencies needed.

### Disk

- `df`


### Song

- Google Play Music Desktop Player: [`gpmdp-remote`](https://github.com/iAndrewT/gpmdp-remote)
- MPD: `mpc`
- Mopidy: `mpc`
- CMUS
- MOC
- Spotify (requires dbus)
- Rhythmbox
- Banshee
- Amarok (requires qdbus)
- Deadbeef
- GNOME Music (requires dbus)
- Lollypop (requires dbus)
- Clementine (requires dbus)
- Pragha
- XMMS2
- Exaile music player (requires dbus)
- Juk (requires dbus)
- Bluemindo (requires dbus)
- Guayadeque (requires dbus)

### Desktop Environment and Window Manager

**Any OS running an X Server**

- `xprop`


### Resolution

**Any OS running an X Server**

- `xorg-xrandr` or `xorg-xdpyinfo` \[1\]

**macOS**

- `screenresolution` \[2\] \[3\]

\[1\] Xrandr is prefered over xdpyinfo as Xrandr supports multi monitor and refresh rate display in the output.

\[2\] `screenresolution` is faster than the built in Mac OS tools.

\[3\] `screenresolution` is installed for you when using homebrew.


### Public IP

**NOTE:** `dig` is the fastest out of the three.

- `dig`, `curl` or `wget`


### GPU

**Linux and GNU Hurd**

- `lspci`

**BSD, Solaris, MINIX, and AIX**

- `glxinfo`
    - Not required on FreeBSD.


## iOS Dependencies

These dependencies can all be installed through Cydia.
Note: The Cydia package installs these dependencies for you.

- `Bourne-Again SHell`
- `Core Utilities`
- `Core Utilities (/bin)`
- `Darwin Tools`
- `system-cmds`
- `Gawk`
- `grep`


## Android Dependencies

- `bash`
- `busybox`

**Note:** I recommend installing `termux` from the Play Store or F-Droid. Termux provides you with a fully working Linux environment, doesn't require root access and includes all dependencies.

**Note:** Neofetch is in Termux's official repos.

