# ComputationalPhysics
This repository aims to solve the problems listed in the book: http://www.physics.ntua.gr/~konstant/ComputationalPhysics/C++/Book/ComputationalPhysicsKNA2ndEd.html 

Dependencies:
1. C/C++ Compiler
2. MAKE
3. GnuPlot

Directory structure of the solutions:
- 0.MySolutions
|---- ChapterN
        |---- Makefile      # generates the binaries using the code in src & install in build directory
        |---- build         # contains the binaries generated from the code in src file
        |---- src           # contains the source code as classes corresponding to each of the problems; 
                            # Main.cpp contains the main() function that creates an object of the problem's class;
                            # run() API of the class executes the actual program.
