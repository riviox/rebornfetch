Smart crop uses the Trim feature from Imagemagick to find the content in a solid background color wallpaper. You can enable this by changing ```$crop_mode``` to ```fit``` or ```fill``` or by using the launch flag ```--crop_mode```. The fill mode should only be used when fit doesn't work correctly as you lose part of the content.

Here are some comparisons between the three crop modes (normal, fit and fill).

### Original Wallpaper
<img src="http://i.imgur.com/yKVtg6e.png" width="700">

### Normal Crop Mode
![](http://i.imgur.com/ueTXlNp.png)

### Fit Crop Mode
![](http://i.imgur.com/KQ27lM7.png)

### Fill Crop Mode
![](http://i.imgur.com/uSssJTz.png)


### Original Wallpaper
<img src="http://i.imgur.com/hfNjAKz.png" width="700">

### Normal Crop Mode
![](http://i.imgur.com/Lq8HwJN.png)

### Fit Crop Mode
![](http://i.imgur.com/4eJOQsI.png)

### Fill Crop Mode
![](http://i.imgur.com/2u5uywi.png)


## An instance where Fill mode yields a better result.


### Original Wallpaper
<img src="http://i.imgur.com/8OWJfWD.png" width="700">

### Normal Crop Mode
![](http://i.imgur.com/W4cliWN.png)

### Fit Crop Mode
![](http://i.imgur.com/FugyUTd.png)

### Fill Crop Mode
![](http://i.imgur.com/vJgRret.png)

