Neofetch 3.0 included a rewrite of how we handle different modes (`image`, `ascii` and etc) which allowed us to add additional image backends to Neofetch. Neofetch now supports displaying images using [`catimg`](https://github.com/posva/catimg), [`libcaca`](http://caca.zoy.org/wiki/libcaca), [`chafa`](https://github.com/hpjansson/chafa), [`iterm2`](https://github.com/gnachman/iTerm2), [`jp2a`](https://csl.name/jp2a/), [`kitty`](https://github.com/kovidgoyal/kitty), [`pixterm`](https://github.com/eliukblau/pixterm), [`pot`](https://github.com/SeungheonOh/pot), [`libsixel`](https://github.com/saitoha/libsixel), [`termpix`](https://github.com/hopey-dishwasher/termpix), [`tycat`](https://www.enlightenment.org/about-terminology), and [`w3m`](https://github.com/tats/w3m).


## Image Backends

Note: The screenshot for `iterm2`, `tycat`, `sixel` and `w3m` is the same since the output in these backends is identical. I also can't get a screenshot of `iterm2` since I don't have a macOS machine. 

 
### Ascii

```sh
# Usage: neofetch --ascii 
#        neofetch --ascii /path/to/ascii
```

![ascii](https://i.imgur.com/pHU40xh.png)


### Caca

```sh
# Usage: neofetch --caca 
#        neofetch --caca /path/to/img
#        neofetch --caca /path/to/dir/
```

![caca](https://i.imgur.com/SBDQgxx.png)


### Catimg

```sh
# Usage: neofetch --catimg 
#        neofetch --catimg /path/to/img
#        neofetch --catimg /path/to/dir/
#        neofetch --catimg --catimg_size 1/2
#        neofetch --catimg /path/to/img --catimg_size 1/2
#        neofetch --catimg /path/to/dir --catimg_size 1/2
```

![catimg](https://i.imgur.com/qOcCNxU.png)


### iTerm2

```sh
# Usage: neofetch --iterm2 
#        neofetch --iterm2 /path/to/img
#        neofetch --iterm2 /path/to/dir/
```

![iterm2](https://i.imgur.com/ys5R5cu.png)


### Jp2a

```sh
# Usage: neofetch --jp2a 
#        neofetch --jp2a /path/to/img
#        neofetch --jp2a /path/to/dir/
```

![jp2a](https://i.imgur.com/d5jVIGY.png)


### Pixterm

```sh
# Usage: neofetch --pixterm
#        neofetch --pixterm /path/to/img
#        neofetch --pixterm /path/to/dir/
```

![pixterm](https://i.imgur.com/Fk4L5tm.png)


### Sixel

```sh
# Usage: neofetch --sixel
#        neofetch --sixel /path/to/img
#        neofetch --sixel /path/to/dir/
```

![sixel](https://i.imgur.com/ys5R5cu.png)


### Tycat

```sh
# Usage: neofetch --tycat 
#        neofetch --tycat /path/to/img
#        neofetch --tycat /path/to/dir/
```

![tycat](https://i.imgur.com/ys5R5cu.png)


### W3m

```sh
# Usage: neofetch --w3m 
#        neofetch --w3m /path/to/img
#        neofetch --w3m /path/to/dir/
```

![w3m](https://i.imgur.com/ys5R5cu.png)


### Off

```sh
# Usage: neofetch --off
```

![off](https://i.imgur.com/7hzZrJi.png)
