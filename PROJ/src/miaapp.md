GETTING STARTED WITH MIA {#miausage}
====================================

###Graphical Mode:

For mia application, the using step for graphical mode is almost the same as the mode of flashphoto application. You will use command ./build/bin/mia to launch the app. There are only two brushes in graphical mode of mia application: mark (for marking a point that you want in the image) and pen. About the filters, there are only five of them in the graphical mode: blur, sharpen, edge detect, threshold, and quantize. There are also basic functionalities such as open and save an png image file and undo/redo for your convenient when working.

![launch MIA application](PROJ/resources/illustration/launch-mia.png)

![Using mark tool on an opened image file within MIA's graphical mode](PROJ/resources/illustration/mark.png)

###Command Line Mode:

A special feature of MIA application is that you can edit image directly only by using command lines in terminal. For this way of using MIA application, you will have thirteen processing commands with the functionalities of all eight filters as in flashphoto application.

- To display help message for the command line mode, just type any invalid command in the terminal or using the command: ./build/bin/mia -h
![Using ./build/bin/mia -h for knowing how to use the processing command lines](PROJ/resources/illustration/help.png)

- For copying an image, using the command: ./build/bin/mia <input.png> <output.png>
- Always run the image processing command before saving out the new file. For example: ./build/bin/mia in.png -sharpen 4 out.png
- Can run more than one image processing command before saving out the new file. For example: ./build/bin/mia input.png -blur 8 -edgedetect output.png

_Notice_:
When you running the terminal, it has to be in /PROJ so if your image is not in /PROJ, you should indicate an absolute path to where the image exists.


For example: _./build/bin/mia resources/illustration/Dorayaki.png -blur 5 -edgedetect resources/illustration/result.png_


Since my image is in illustration directory, which is inside the resources directory, so I have to show the path to where the image Dorayaki.png exist as well as where I want my result.png which is the output image being created.

![Result of running the above example image processing command lines](PROJ/resources/illustration/result.png)

* * * *

Both two application are built on the [GLUI](http://glui.sourceforge.net) library with support codes and iter1-sol code from the CSCI 3081W's Professors and TAs.
