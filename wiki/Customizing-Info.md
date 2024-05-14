The neofetch config file contains a function near the top which gives you total freedom over customizing how info is displayed in the info column. Since the config file is a bash script and this is a function, you can use any bash syntax to customize it.

I've also created a few "helper" functions to make customization easier. The functions are called `prin`, `info` and `color`.

## Table of Contents

<!-- vim-markdown-toc GFM -->
* [Config File Location](#config-file-location)
* [Print Info Function](#print-info-function)
* [Adding Custom Info](#adding-custom-info)
    * [info](#info)
    * [prin](#prin)
    * [color](#color)
    * [Other](#other)
* [Removing Info](#removing-info)
* [Rearranging info](#rearranging-info)
* [More complex examples](#more-complex-examples)
    * [Display the current weather](#display-the-current-weather)
    * [Print color blocks on the top and bottom](#print-color-blocks-on-the-top-and-bottom)
    * [Speed up the script by running the functions asynchronously](#speed-up-the-script-by-running-the-functions-asynchronously)

<!-- vim-markdown-toc -->

## Config File Location

### GNU/Linux Systems

The per-user location for neofetch's config is `${HOME}/.config/neofetch/config.conf` and neofetch will copy its [default config](https://github.com/dylanaraps/neofetch/wiki/Config-File) here on first run if installed correctly (Using the Makefile or a Distro package).

Neofetch also installs a system-wide editable config file at `/etc/neofetch/config.conf` (This is where it copies the user config from).

## Print Info Function

The strings in double quotes ("Model") are the subtitles for each info line and can be changed to whatever title you like or just removed altogether.

Here's what the function looks like:

```sh
print_info () {
    info title
    info underline

    info "Host" model
    info "OS" distro
    info "Kernel" kernel
    info "Uptime" uptime
    info "Packages" packages
    info "Shell" shell
    info "Resolution" resolution
    info "DE" de
    info "WM" wm
    info "WM Theme" wm_theme
    info "Theme" theme
    info "Icons" icons
    info "Terminal" term
    info "Terminal Font" term_font
    info "CPU" cpu
    info "GPU" gpu
    info "Memory" memory

    # The lines below with a '#' in front are additional info functions
    # that are disabled by default. Removing the '#' enables them and adding
    # a '#' to the start disables them again. You can add a '#' to any of the
    # lines in this function to disable their output.

    # info "CPU Usage" cpu_usage
    # info "Disk" disk
    # info "Battery" battery
    # info "Font" font
    # info "Song" song
    # info "Local IP" local_ip
    # info "Public IP" public_ip
    # info "Users" users
    # info "Birthday" birthday

    info cols
}

```

## Adding Custom Info

The script comes with two helper functions that make it easier to display more info.

### info

```sh
Usage: info "subtitle" function
Usage: info function

# Print Memory
info "Memory" memory # Memory: 100MB / 1000MB
info memory          # 100MB / 1000MB
```

Full list of functions:

`distro` `model` `kernel` `uptime` `packages` `shell` `resolution`
`de` `wm` `wm_theme` `theme` `icons` `cpu` `gpu` `memory`
`font` `disk` `battery` `song` `local_ip` `public_ip` `users`
`birthday` `term` `term_font`  `cpu_usage`

Special functions:

`underline` `title`

Old functions:

* `line_break` – removed in [85a1bd0](https://github.com/dylanaraps/neofetch/commit/85a1bd0af7e5b5752683c586305164f0d6444550), use `prin` instead

### prin

You can also just use `printf` or `echo` but you'll have to format/color
the text yourself.

```sh
Usage: prin "Custom message" or prin "Subtitle" "Custom message"

# Print a custom message
prin "They call me Stacy"

# Print a custom info line
prin "Date" "$(date)"

# Print a custom message and color it blue
prin "$(color 4)That's not my name"

# Print the current weather
prin "Weather" "$(curl wttr.in/?0?q?T | awk '/°(C|F)/ {printf $(NF-1) $(NF) " ("a")"} /,/ {a=$0}')"
```

### color

This function allows you to add color to strings.

```sh
Usage: color num
       color fg # fg is the default foreground color of your colorscheme.

# Print a custom message and color it blue
prin "$(color 4)That's not my name"

# Print a custom message and color it.
prin "$(color 1)Hi, $(color 2)They $(color 3)call $(color 4)me $(color 5)Stacy!"

```

### Other

```sh
# Using echo
echo "hello, world"
echo -e "$(color 3)Date: $(color 7)$(date)"

# Using printf
printf "%s\n" "hello, world"
printf "%s\n" "$(color 3)Date: $(color 7)$(date)"
```

## Removing Info

You can easily disable info from printing by adding a `#` to the start of the line. See below where I disable **Packages** from printing:

```sh
print_info() {
    info title
    info underline

    info "Model" model
    info "OS" distro
    info "Kernel" kernel
    info "Uptime" uptime
    # info "Packages" packages
    info "Shell" shell
    info "Resolution" resolution
    info "DE" de
    info "WM" wm
    info "WM Theme" wm_theme
    info "Theme" theme
    # ...
}
```

## Rearranging info

You can also move the lines inside the `print_info()` function around to change the order they get printed in. See this custom ordering below:

```sh
print_info() {
    info cols

    info "OS" distro
    info "Uptime" uptime
    info "Kernel" kernel

    prin

    info "Model" model
    info "Packages" packages
    info "Shell" shell
    info "Resolution" resolution
    info "DE" de
    info "WM" wm
    info "WM Theme" wm_theme
    info "Theme" theme
    # ...
}
```

## More complex examples

### Display the current weather

```sh
prin "Weather" "$(curl wttr.in/?0?q?T | awk '/°(C|F)/ {printf $(NF-1) $(NF) " ("a")"} /,/ {a=$0}')"
```

### Print color blocks on the top and bottom

```sh
print_info () {
    info cols

    info "Model" model
    info "OS" distro
    info "Kernel" kernel
    info "Uptime" uptime
    info "Packages" packages
    info "Shell" shell
    info "Resolution" resolution
    info "DE" de
    info "WM" wm
    info "WM Theme" wm_theme

    info cols
}

```

### Speed up the script by running the functions asynchronously

You can make the script 2x faster by gathering the info asynchronously, the only caveat is that the order that all of the info is printed in will be based on what completes first. You can add this to your printinfo function by adding an `&` sign to the info lines you want to be asynchronous then by adding a single `wait` to the bottom of the function.

```sh
print_info () {
    # Lines without an '&' sign will be displayed in
    # the order they appear here.
    info title
    info underline

    info "OS" distro &
    info "Kernel" kernel &
    info "Uptime" uptime &
    info "Packages" packages &
    info "Shell" shell &
    info "Window Manager" wm &
    info "GTK Theme" theme &
    info "Icons" icons &
    info "CPU" cpu &
    info "GPU" gpu &
    info "Memory" memory &

    # Wait for the functions to complete
    wait

    info cols
}
```
