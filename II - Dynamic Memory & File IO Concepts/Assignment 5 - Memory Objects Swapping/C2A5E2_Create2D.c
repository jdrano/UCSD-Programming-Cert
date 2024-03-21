//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/13/24
// C2A5E2_Create2D.c
// Win10
// Visual Studio 2022
//
// This file contains a function that creates a 2D array as one contingous
// block of memory. This allows us to free it easily by using the reference for
// said created 2D array.
//

#include <stdio.h>
#include <stdlib.h>

#include "C2A5E2_Type-Driver.h"

Type **Create2D(size_t rows, size_t cols)
{
    Type **testArray;
    
    // Allocate memory for the rows in of the 2D array
    if ((testArray = 
        malloc((rows * sizeof(Type *)) + (rows * cols * sizeof(Type)))) == NULL)
    {
        fputs("Out of memory\n", stderr);
        exit(1);
    }

    // Create a Type pointer to beginning of data block
    Type *data = (Type *)(testArray + rows);
    for (size_t curr_place_in_mem = 0; curr_place_in_mem < rows;
        curr_place_in_mem++)
    {
        // Set each row pointer to the beginning of its respective row
        testArray[curr_place_in_mem] = data + (curr_place_in_mem * cols);
    }

    return testArray;
}

void Free2D(void *p)
{
    free(p);
}
