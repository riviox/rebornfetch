## WIP

### [Linux] Is Neofetch's memory output correct? 

> "\*insert program\* shows different memory amounts to Neofetch."

The correct way to calculate memory usage (and what Neofetch currently does) on Linux is the following:

```sh
MemUsed = Memtotal + Shmem - MemFree - Buffers - Cached - SReclaimable
```
Until late 2016 `htop`, `conky`, `Screenfetch`, `Neofetch` and a lot of other programs were displaying the incorrect memory usage amount. Almost all of the programs I could find have been updated to fix this but there are still a few programs displaying incorrect usage. Those of you using older versions of these programs are probably where this question comes from.

Source: [KittyKatt/screenFetch/issues/386](https://github.com/KittyKatt/screenFetch/issues/386#issuecomment-249312716)

**TL;DR**: Yes


### [Linux] Neofetch reports inaccurate distro name

>It's supposed to be [insert a downstream distro here], but it shows [insert an upstream distro here] instead!

When Neofetch detects a Linux distro it first looks for the `lsb_release` command before searching for the `/etc/os-release` file. Since some downstream distros mostly utilize their upstream distro's repositories they'll include the upstream distro's version of `lsb_release`. The prominent case is with Antergos and Arch with `lsb_release` installed, Antergos will be detected as "Arch" instead. 

When the upstream's version of `lsb_release` is executed the output will be that of the upstream distro. (Arch output on Antergos and etc). This means that unless the downstream distro supplies their own version of `lsb_release` in their own repository, the output will be the upstream distro's.

We had deleted support for `lsb_release` but more complaints came up because it proved to be very useful in detecting a wide number of distros. Almost all distros we officially support provide their own `lsb_release` package which makes `lsb_release` output the correct information. See [issues/493](https://github.com/dylanaraps/neofetch/issues/493)

>So, shouldn't you add an exception rule in cases like these?

A good distro will always provide their own `lsb-release` file, otherwise they will be practically seen as the upstream distro with fancy modifications.

>So, is there any workaround?

Yes, actually. You'd have to remove your `lsb-release` (or any equivalent) package. (That is, if the distro filled their `/etc/*-release` properly. Contact your distro's maintainers if they don't).

### [Linux/FreeBSD] Why doesn't getgpu show my exact video card model?

If your `lspci | grep "VGA"` (Linux) output looks like this:

`01:00.0 VGA compatible controller: NVIDIA Corporation Device 1401 (rev a1)`

Instead of this:

`01:00.0 VGA compatible controller: NVIDIA Corporation GM206 [GeForce GTX 960] (rev a1)`

or if your `pciconf -lv | grep -B 4 -F VGA` (FreeBSD) output looks like this

```
vgapci0@pci0:0:2:0:    class=0x030000 card=0x00000000 chip=0xbeef80ee rev=0x00 hdr=0x00
    vendor     = 'InnoTek Systemberatung GmbH'
    device     = 'beef'
    class      = display
    subclass   = VGA
```

Instead of this:


```
vgapci0@pci0:0:2:0:    class=0x030000 card=0x00000000 chip=0xbeef80ee rev=0x00 hdr=0x00
    vendor     = 'InnoTek Systemberatung GmbH'
    device     = 'VirtualBox Graphics Adapter'
    class      = display
    subclass   = VGA
```

Then you're affected by the issue.

There are two possible causes. This can be caused by your `/usr/share/misc/pci.ids\*` (Linux) or `/usr/local/share/pciids/pci.ids\*` (FreeBSD) files being outdated and you can fix it by running

`sudo update-pciids` (Linux only)

If the list is not updated even after running the command above, that means your GPU is brand new, and no one has registered your GPU to the pci-ids repository.

You can submit an issue/contact us through gitter, or you can add it yourself to https://pci-ids.ucw.cz/. Make sure you have the right vendor ID and the device ID by checking `lspci -nn` (Linux) or `chip=0xaaaabbbb` with `aaaa` as your device ID and `bbbb` as your vendor ID (FreeBSD) and read the guidelines.