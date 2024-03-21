//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/17/24
// C2A6E1_GetPointers.c
// Win10
// Visual Studio 2022
//
// Contains 2 pointers to function so that printf and puts get called during
// runtime.
//

#include <stdio.h>

int (*GetPrintfPointer(void))(const char *format, ...)
{
    int (*pPrintf)(const char *, ...) = printf;
    return pPrintf;
}

int (*GetPutsPointer(void))(const char *str)
{
    int (*pPuts)(const char *str) = puts;
    return pPuts;
}
