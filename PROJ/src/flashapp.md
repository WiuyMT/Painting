GETTING STARTED WITH FLASHPHOTO {#flashusage}
=============================================

For running the application using "make all" command for installation first.
![](PROJ/resources/illustration/make-all.png "make all")

After the installation, you can launch the application by using "./build/bin/flashphoto" command on terminal and a canvas will appear on the desktop.
![](PROJ/resources/illustration/launch.png "./build/bin/flashphoto")

The canvas interface will have a flashphoto tool bar opened as well when the application is launched. You can open a file in FlashPhoto to edit it with brush tools and filters, or you can just drawing your own picture by using brush tools and filters without using a opened file.
![](PROJ/resources/illustration/canvas.png "flashphoto's interface")
![](PROJ/resources/illustration/canvas1.png "Interface Intro")

###BRUSHES
There are many choices for brush style:
- Pen brush is a regular style choice used as a standard/default style for the application when you launch flashphoto application.
- Calligraphy pen brush has a sharper stroke compared to regular pen stroke and have a really artistic look.
- Chalk style brush will give a bumpy effect.
- Highlighter style brush which is as its name, will help you highlight the word or detail that you want to notice in the picture with the choice of your favorite color from the tool color.
- Spray can style brush makes the imitation of the can-spraying action become more easy with the effect almost like chalk style but will darker if you just spray at one spot only.
- Blur style brush is a special effect brush that help blurring a specific spot in the picture that you want.
- Eraser style seven brushed above and their stroke shapes when drawinbrush is the important one when you need to fix anything in your picture by helping erase the part that you want.

![](PROJ/resources/illustration/example.png "An example of editing an opened image file using seven brushed above and their stroke shapes when drawing")

###FILTERS
There are also many choices for filters feature to make your photo look better:
- Threshold filter is your friend when wanting to make beautiful binary images.
- Saturation filter helps increase or decease the colorfulness of the image.
- Adjust RGB filter, also called channels filter, will give you a hand in scaling up or down the intensity of each color channel red, green, or blue.
- Quantize filter is a feature that reduces the number of colors in the image by binning.
- Blur filter will blur the image in proportion to the amount of your choice.
- Motion blur filter will blur the image to specific direction that you want. In this application, you have four possible directions: North-to-South, East-to-West, Northeast-to-Southwest, and Northwest-to-Southeast.
- Sharpen filter will be the one you need when wanting your image look sharper in each of its edge.
- Edge detection filter shows the edge of your image.

![](PROJ/resources/illustration/channels.png "An example of editing an opened image file using channel filter with adjust values as shown in the figure")

![](PROJ/resources/illustration/edge.png "Another example of editing an opened file and drawing stroke on canvas using edge detection feature")

One more important thing when you use this application is that the undo and redo buttons which help you go back to the image before and after editing at one point that you feel unsatisfied about the condition of your image. These functionalities will help you a lot in editing process, which is a more convenient way.

* * * *

Both two application are built on the [GLUI](http://glui.sourceforge.net) library with support codes and iter1-sol code from the CSCI 3081W's Professors and TAs.
