I get a lot of comments/questions about how to get w3m-img mode working with
neofetch. This wiki page will guide you through setting up neofetch/w3m-img and
will try to explain the various quirks of this mode.

## Enabling Image Mode

Neofetch 2.0.1 changes the default image mode to `ascii` from `wallpaper`. From 2.0.1 onwards an additional step is required to use image mode.

You can either use the launch option `--w3m` (also `--w3m /path/to/img` / `--w3m /path/to/dir/`) or you can edit the config file to enable image mode. The option you have to change is called `image_backend`, just change this from `ascii` to one of the other valid values and image mode will be enabled.

## Requirements


#### Dependencies

- `w3m-img`
    - Image rendering in the terminal.
    - This is sometimes bundled together with `w3m`.
    - `kitty`, `Terminology` and `iTerm` users don't need to install w3m-img.

- `imagemagick`
    - Generating thumbnails and cropping the images.

- A terminal emulator that supports `\033[14t` or `xdotool` or
`xwininfo + xprop` or `xwininfo + xdpyinfo`
    - Getting the terminal window size in pixels so that we can size the image correctly.

#### Terminal Emulator

The table below lists my testing of various terminal emulators, what works and
what doesn't.

| Terminal Emulator | w3m-img | Quirks |
| ----------------- | ------- | ------ |
| Gnome-terminal    | Yes     | - Image disappears on window focus and resize
|                   |         | - Possible issues on Fedora, see [#295](https://github.com/dylanaraps/neofetch/issues/295)
| iTerm             | N/A     | See \[1\] |
| konsole           | Yes     |
| st                | Yes     | Image disappears on window focus and resize |
| Terminator        | Yes     | Image disappears on window focus and resize |
| Terminology       | N/A     | See \[2\] |
| Termite           | Yes     | Highlighting the image makes the highlighted parts disappear |
| tilda             | No      |
| URxvt             | Yes     | Image disappears on window focus and resize |
| Xfce4-terminal    | Yes     | Image disappears on window focus and resize
| Xterm             | Yes     |
| kitty             | N/A     | See \[3\] |
| alacritty         | No      | 

\[1\] iTerm doesn't require `w3m-img` to display images. Instead it uses a
set of escape sequences built into iTerm.

\[2\] Terminology doesn't require `w3m-img` to display images. Instead it uses
a builtin program called `tycat`.

\[3\] kitty doesn't require `w3m-img` to display images. Instead it uses
a builtin program called `kitty +kitten icat`.

Note: For image mode to work, the `w3m-img` column must say `yes` and you must have
the dependencies installed.

## Image source

Neofetch by default will try to use your current wallpaper as the image. If the
wallpaper detection fails we fallback to ascii mode, when that happens you should
try and launch neofetch with `--w3m --source path/to/image` or `--w3m --source path/to/dir/`.

The list below shows the current wallpaper setters we support.

**Linux / BSD**

- feh
- nitrogen
- gsettings

**macOS / Windows**

- Builtin wallpaper setter

If your wallpaper setter isn't listed here and there's an easy way to find where
the current wallpaper is stored, open an issue and I'll gladly add support for
it.

## Usage

Once you've installed `w3m-img`, `imagemagick`, have a terminal emulator that
meets the criteria above and have a working image source, neofetch should
display images correctly.

if neofetch won't display the images check if the terminal support images. To do this you need to launch the command

`w3m google.com`

If you don't see it your terminal support only text, no image. 

If neofetch still won't display the images then you should open a new issue on
github and provide me with a verbose log.
