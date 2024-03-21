//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/18/24
// C2A3E4_OpenFile.c
// Win10
// Visual Studio 2022
//
// This file contains a function that returns a pointer to an open file upon
// a successful open.
//

#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(const char *fileName)
{
    FILE *fptr;

    fptr = fopen(fileName, "r");

    // Print to stderr if file fails to open
    if (fptr == NULL) {
        fprintf(stderr, "Error opening file %s", fileName);
        exit(1);
    }
    else {
        return fptr;
    }
}
