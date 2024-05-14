This is the format neofetch uses for it's ascii art files and the format you should follow when adding ascii art to neofetch or when specifying custom ascii art with:` --ascii /path/to/ascii_file`.

The ascii art is read as plaintext so the only character you have to escape is the backslash `\`.

### Here's an example:

```sh
# ascii/distro/redstar
${c1}                    ..
                  .oK0l
                 :0KKKKd.
               .xKO0KKKKd
              ,Od' .d0000l
             .c;.   .'''...           ..'.
.,:cloddxxxkkkkOOOOkkkkkkkkxxxxxxxxxkkkx:
;kOOOOOOOkxOkc'...',;;;;,,,'',;;:cllc:,.
 .okkkkd,.lko  .......',;:cllc:;,,'''''.
   .cdo. :xd' cd:.  ..';'',,,'',,;;;,'.
      . .ddl.;doooc'..;oc;'..';::;,'.
        coo;.oooolllllllcccc:'.  .
       .ool''lllllccccccc:::::;.
       ;lll. .':cccc:::::::;;;;'
       :lcc:'',..';::::;;;;;;;,,.
       :cccc::::;...';;;;;,,,,,,.
       ,::::::;;;,'.  ..',,,,'''.
    ```
    ........          ......
```

### Rules:

 - You have to escape `\.` (eg `\\`)

### Features:

 - You can use `${c1}` to `${c6}` to color the ascii.
        These are evaluated after we read the file.
 - You can pass the flag `--ascii_colors 1 2 3 4 5 6` to set the colors.
    - This changes the values of `${c1}` to `${c6}`
    - `--ascii_colors 2 5 6 1` changes `${c1}` to `Green`, `${c2}` to `Magenta` and etc.
