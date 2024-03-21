//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/27/24
// C2A7E4_ProcessStructures.c
// Win10
// Visual Studio 2022
//
// Contains functions that reverse the endians for the members of a passed in
// Test struct, and functions that read and write into said structures.
// 
// Questions
// 1. The values were correctly reverse endianed on my machine.
// 2. 4 bytes were added to data align the float and double.
//

#include <stdio.h>
#include <stdlib.h>

#include "C2A7E4_Test-Driver.h"

void *ReverseEndian(void *ptr, size_t size);

struct Test *ReverseMembersEndian(struct Test *ptr)
{
    ReverseEndian(&ptr->flt, sizeof(ptr->flt));
    ReverseEndian(&ptr->dbl, sizeof(ptr->dbl));
    ReverseEndian(&ptr->vp, sizeof(ptr->vp));

    return ptr;
}

struct Test *ReadStructures(struct Test *ptr, size_t count, FILE *fp)
{
    // If we didn't read 3 separate structures, exit failure
    if (fread(ptr, sizeof(struct Test), count, fp) != count)
    {
        fprintf(stderr, "Unable to read %zu structures.\n", count);
        exit(1);
    }

    return ptr;
}

struct Test *WriteStructures(const struct Test *ptr, size_t count, FILE *fp)
{
    // If we didn't write to 3 separate structures, exit failure
    if (fwrite(ptr, sizeof(struct Test), count, fp) != count) 
    {
        fprintf(stderr, "Error: Unable to write %zu structures.\n", count);
        exit(1);
    }

    return (struct Test *)ptr;
}
