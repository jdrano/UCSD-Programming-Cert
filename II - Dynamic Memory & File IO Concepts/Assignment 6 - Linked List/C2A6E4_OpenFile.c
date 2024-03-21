//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/18/24
// C2A6E4_OpenFile.c
// Win10
// Visual Studio 2022
//
// Contains a function with the purpose of opening a file. Exits and prints 
// error if no such file is found.
//

#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(const char *filename)
{
    FILE *in_file = fopen(filename, "r");
    
    // If file unable to be opened we exit
    if (in_file == NULL)
    {
        fprintf(stderr, "File %s failed to open", filename);
        exit(EXIT_FAILURE);
    }

    return in_file;
}
