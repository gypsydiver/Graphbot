Graphbot
========

A programming language with graphical output made with Flex/Bison in C++ with OpenGL Libraries

To run in OSX:

$ bison -d graphbot.y

$ flex graphbot.l

$ g++ graphbot.tab.c lex.yy.c -ll -­o graphbot

$ ./graphbot textfile.txt
