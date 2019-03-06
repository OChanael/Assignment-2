# Assignment-2
Assignment 2: Game of Life

Ori Chanael
ID: 2270254

Runtime Errors:

SelectMode.cpp: In member function ‘int Modes::ClassicMode(int, int, char**&)’:
SelectMode.cpp:180:27: error: ‘printMethod’ was not declared in this scope
            t.PrintResults(printMethod, generationCount, board, boardLength, boardWidth);
                           ^~~~~~~~~~~
SelectMode.cpp:206:28: error: ‘printMethod’ was not declared in this scope
             t.PrintResults(printMethod, generationCount, board, boardLength, boardWidth);
                            ^~~~~~~~~~~
SelectMode.cpp: In member function ‘int Modes::DonutMode(int, int, char**&)’:
SelectMode.cpp:405:29: error: ‘printMethod’ was not declared in this scope
              t.PrintResults(printMethod, generationCount, board, boardLength, boardWidth);
                             ^~~~~~~~~~~
SelectMode.cpp:433:25: error: ‘printMethod’ was not declared in this scope
          t.PrintResults(printMethod, generationCount, board, boardLength, boardWidth);
                         ^~~~~~~~~~~
SelectMode.cpp: In member function ‘int Modes::MirrorMode(int, int, char**&)’:
SelectMode.cpp:611:29: error: ‘printMethod’ was not declared in this scope
              t.PrintResults(printMethod, generationCount, board, boardLength, boardWidth);
                             ^~~~~~~~~~~
SelectMode.cpp:637:25: error: ‘printMethod’ was not declared in this scope
          t.PrintResults(printMethod, generationCount, board, boardLength, boardWidth);


(I don't know why it formatted like that, it's fine in Atom)

All attempts to transfer over the PrintResults method (specifically the printMethod variable that
contained the user's choice of "pause, enter, or file") from the TerminalNavigation class to
the Modes class was met with failure. As a result, the code does not work and is inoperable.

Source Files:
main.cpp
SelectMode.cpp
SelectMode.h
TerminalNavigation.cpp
TerminalNavigation.h

References:
Stackoverflow.com
cplusplus.com
Discussions with Zach Jagoda
