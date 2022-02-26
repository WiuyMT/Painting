DEVELOPER RESOURCES {#developerSources}
=======================================

Introduction
-------------

Welcome to the FlashPhoto project's developer resources page. Here you can find all of the information that you need to extend our project for your own interest or use it for your clients. The more people contribute to this project, the more it becomes better and better.

Programming Reference
----------------------

[This link will lead to documentation for all the code in this project.](annotated.html)

High-Level Design
------------------

The design started as a single painting application FlashPhoto only and using factor and template method in design. Some main classes of the design are Filter abstract class, which also has a subclass as an abstract class that is Convolution Filter.
desktop. The UML below shows the relation of Filter class and its subclasses. Four basic filters are direct sub-classes of Filter and the four convolution filters are direct sub-classes of Convolution Filter.
![Filter abstract class](PROJ/resources/illustration/filter-class.png)

The similar structure is also applied for Tool class which is the abstrac class of total eight tools for whole two applications. The Tool class also has associate relation with Float Matrix class, ColorData class, as well as PixelBuffer class as illustrated below.
![Tool abstract class](PROJ/resources/illustration/tool-class.png)
![Tool relationship](PROJ/resources/illustration/tool-relate.png)

Since later, the project was developed to handle a more concentrating feature for medical usage, the organization of the code had a little change. We now re-factor all the code adjust for the changing. All the Tool class related files and Filter class related files are moved into a new directory called imagetools. Everything in imagetools will be build as a library so that both applications FlashPhoto and Mia can link to the library and use all the functions/methods in our new library called libimagetools. The structure of the re-factoring process is shown as below.
![Summary of the directory structure after re-factoring](PROJ/resources/illustration/structure.png)

After doing all the re-factoring and developing the command line feature for mia, every time you run "make all" in /PROJ directory, the library libimagetools will be build in ./build/lib/ directory and both applications can access that library through linking.

Coding Style
-------------

The project is strictly follow the rule from Google C++ Style Guide. For more advance details and reading about the naming style guide, please look futher [here](https://google.github.io/styleguide/cppguide.html)

_Notice_: some of the most error that people have for this naming style that should be noticed are the space errors.
- There should not be any extra space at the end of each code line.
- Do not use tab for indent but using space instead, though it will take a little bit time but using space it easy to monitor which indent line is for what loop or class, especially when you have nested loop or class.
- Do not use too many break line, you should group them so that it is easy to read and keep minimum amount of line in a class or functions.
- There should be less than 80 characters per line
- Always keep the functions/methods as short as you can, if it become too long when you coding, please break them down or get another approach.
- The variables, classes, methods/functions' name should be as much descriptive as possible and avoid to have names that too similar that can cause the confusion.

Common Tasks
-------------

This task is a tutorial part for programmers know how to add a new filter to this project as desired. As mentioned in the high level design part, when you want to add a new filter
, that new filter should be directly related to filter class or convolution filter class, which means a sub-class of filter class; or you can create a new abstract class with new functionalities of new filter, but it must also a sub-class of the filter class.

After finishing the structure part, you can create add your new filter and implement the algorithm for that new filter. If your new filter has a simple approach like the basic filters, you can based on four basic filters to add a new filter and make an Apply<newfilter> function in image_editor.h/cc as the four basic filters. The similar approach if your new filter have similar feature as four convolution filters. If you want to create a whole new filter features, you can base on the structure of ConvolutionFitler abstract class' structure to make a new one for you.

* * * *

Both two application are built on the [GLUI](http://glui.sourceforge.net) library with support codes and iter1-sol code from the CSCI 3081W's Professors and TAs.
