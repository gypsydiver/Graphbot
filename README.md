Graphbot
========

A programming language with graphical output for OS X  made with Flex/Bison in C++ with OpenGL 
and wxWidgets Libraries

There are a couple of steps necessary to run Graphbot on your system.
We can divide Graphbot in two major parts, the parser, which is in charge of anaylzing the 
input language and generating a file with a list of cuadruples, and the virtual machine, which
takes these cuadruples and renders the output and well as managing the UI.

The parser needs to be compiled with make and such make file can be found in the /parser folder.
the following commands can be used to compile it :
	make graphbot
This will copy an executable file to the desired /resources folder for the virtual machine to use.

Now here comes the tricky part:
To build the desired Graphbot.app we first need to download the wxWidgets library,
that can be done here: http://wxwidgets.org/
Please note that the version to which this application has been tested was 3.0.
Follow the instructions included there to compile the library for the Cocoa Framework and 
make sure the samples and demos run properly.

In your WxWidgets root directory, go to /build/osx/ folder and open the wxcocoa.xcodeproj project
and run it. The built product should be (depending of your Xcode default ouput location) in 
a folder of the following type:
	Build/Products/Release/libwx_osx_cocoa_static.a

Make a mental note of the location of this file.

Once that is done, we need to configure the Xcode project to include those libraries in 
compile time.

Select the Graphbot target, then click on Build settings

Edit the following User-Defined environment variable:
WXROOT = the location of your wxWidgets installation

Then go to Build phases and add the file you built to the "Link Binary with libraries" section.

That should make it, build the Xcode project, the resulting .app file should be again, depending 
in your Xcode output directory in a directory of the following fashion:
	Build/Products/ Release/ or Debug/ respectively

Enjoy Graphbot!

P.S.
If you happen to run into any trouble, check the following links for help:
http://wiki.wxwidgets.org/Creating_Xcode_projects_for_wxWidgets_applications
https://groups.google.com/forum/#!msg/wx-users/cjV7hZEw3dE/z4MhzQUzh_QJ
 

