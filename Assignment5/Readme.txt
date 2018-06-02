Nicholas Ellul 101064168


This software was created for COMP 2401 Assignment 5 to demonstrate reading files, inter process communication,
and signals.

Files:
    createBinary.c: A program that creates a binary files with the specified numbers
    isPrime.c: Base program that checks if a number is prime or not
    singleSpawn.c; Program that reads the first number from a binary file then calls a child to check if the number is prime or not
    singlePrime.c: Program that retrieves the first number in a binary file, then morphs into isPrime to evaluate the number
    multiSpawn.c: Program that creates child processes to check if their allocated number is prime or not.
    prime.bin: File containing unsigned numbers in Binary format
    prime.txt: File containing numbers in ASCII format.

Makefiles:
    Makefile1 creates executable for singlePrime.c
    Makefile2 creates executable for singleSpawn.c
    Makefile3 creates executable for multiSpawn.c
    Makefile4 creates executable for multiSpawnSignal.c

Created Executables
    singleMorph - Makefile1
    singleSpawn - Makefile2
    multiSpawn - Makefile3
    multiSpawnSignal - Makefile4

How to compile?
    Each makefile will automatically create an executable for you (Read above)
    The makefile can be run by executing...
        make -f NAME_OF_MAKEFILE

    isPrime can be compiled separately if wanted by running
    gcc -o isPrime isPrime.c

    createBinary can be compiled by running
    gcc -o createBinary createBinary.c

Issues and limitations
   -  Handling for all errors hasn't been implemented. Since all makefiles rely on isPrime, each of their
     clean rules will clean this file. This means that if you run all the makefiles, you may get an error
     saying that isPrime couldn't be found. This is normal and fine since it means that you already cleaned it up.
     - Also, the filename you provide must have the .bin file extension and must be a binary file.
     - The executable for isPrime must be named isPrime for the other executables to work.
    - The numbers inputted are expected to be positive
How to use?

    To run isPrime run
    ./isPrime NUMBER where number is a number you wish to check if its prime or not.
    This will return 1 if its prime or 0 otherwise.

    To run createBinary run
    ./createBinary NAME_OF_FILE.bin NUMBERS...
    Where name_of_file is the name of your new file, and numbers is bunch of positive numbers
    separated by spaces

    All other files are run by typing
    ./EXECUTABLE_NAME BINARY_FILE_NAME.bin
    where executable name is the name of the executable and binary file name is the name of
    a binary file containing unsigned integers.
