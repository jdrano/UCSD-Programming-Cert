//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/13/24
// C2A5E1_SwapObjects.c
// Win10
// Visual Studio 2022
//
// This file contains a function swaps the objects that two void pointers are 
// looking at. 
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SwapObjects(void *pa, void *pb, size_t size)
{
    void *tmp;
    // Check for safe memory allocation
    if ((tmp = malloc(size)) == NULL)
    {
        fputs("Out of memory\n", stderr);
        exit(1);
    }
    memcpy(tmp, pa, size);
    memcpy(pa, pb, size);
    memcpy(pb, tmp, size);

    free(tmp);
}
