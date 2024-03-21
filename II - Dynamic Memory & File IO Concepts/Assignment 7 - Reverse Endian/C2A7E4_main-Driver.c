#define INSTRUCTOR_FILE    // DO NOT DEFINE THIS MACRO IN ANY FILES YOU CREATE

/***  YOU DO NOT NEED TO UNDERSTAND THE CODE IN THIS FILE TO WRITE YOURS  ***/

/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/
/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/
/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/

//****************************************************************************
// Everything in this file was written to help test/verify your code and must
// not be altered in any way.  Do not rename this file or copy anything from
// it into your file(s).  This file does not necessarily represent good coding
// technique, proper formatting/style, or meet the requirements your code must
// meet.  You do not need to understand the code in this file to write yours.
//****************************************************************************
#ifdef INSTRUCTOR_FILE

#include <stdio.h>
#include <stdlib.h>

#include "C2A7E4_Test-Driver.h"

FILE* OpenTemporaryFile(void);
struct Test* ReverseMembersEndian(struct Test* ptr);
struct Test* ReadStructures(struct Test* ptr, size_t count, FILE* fp);
struct Test* WriteStructures(const struct Test* ptr, size_t count, FILE* fp);

#define Elements(array) (sizeof(array)/sizeof((array)[0]))

typedef unsigned char UChar;

int main(void)
{
    const char* const MESSAGE =
        "Error in WriteStructures or ReadStructures or both:\n";
    UChar* cp;
    int elemNo;
    size_t byteNo;
    FILE* temporaryFile;
    int gotError = 0;

    struct Test x[] =                      // an array of structures
    {                                      // declare and initialize
       {23.6F, -425e-6, (void*)0x2345},   // structure 0
       {2, 1, 0},                          // structure 1
       {-6, 3.3, NULL}                     // structure 2
    };

    struct Test y[Elements(x)] =           // an array of structures
    {
       {123.456F, 789.12, (void*)0x9876}, // structure 0
       {69.0F, 24, (void*)0x1928A},       // structure 1
       {-59.2F, 89.48e-16, (void*)0xABC}  // structure 2
    };

    size_t fileSize;

    // file for unaltered structures
    temporaryFile = OpenTemporaryFile();
    // write multiple structures
    WriteStructures(x, Elements(x), temporaryFile);
    // back to beginning
    rewind(temporaryFile);
    for (fileSize = 0; fgetc(temporaryFile) != EOF; ++fileSize)
        ;
    if (fileSize != sizeof(x))
    {
        printf(
            "Error in WriteStructures: The wrong number of bytes were written.\n"
            "This sometimes indicates that you are attempting to write the "
            "members of a structure to a file individually and possibly in "
            "\"text\" rather than writing the entire structure at once in "
            "\"binary\".\n");
        gotError = 1;
    }
    rewind(temporaryFile);
    // read multiple structures
    ReadStructures(y, Elements(y), temporaryFile);
    printf("\n");

    // Structure member values before and after write/read.
    for (elemNo = 0; elemNo < (int)Elements(x); ++elemNo)
    {
        if (y[elemNo].flt != x[elemNo].flt)
        {
            printf("%s", MESSAGE);
            printf("Original structure[%d].flt: %g\n", elemNo, x[elemNo].flt);
            printf("Readback structure[%d].flt: %g\n\n", elemNo, y[elemNo].flt);
            gotError = 1;
        }
        if (y[elemNo].dbl != x[elemNo].dbl)
        {
            printf("%s", MESSAGE);
            printf("Original structure[%d].dbl: %g\n", elemNo, x[elemNo].dbl);
            printf("Readback structure[%d].dbl: %g\n\n", elemNo, y[elemNo].dbl);
            gotError = 1;
        }
        if (y[elemNo].vp != x[elemNo].vp)
        {
            printf("%s", MESSAGE);
            printf("Original structure[%d].vp: %p\n", elemNo, x[elemNo].vp);
            printf("Readback structure[%d].vp: %p\n\n", elemNo, y[elemNo].vp);
            gotError = 1;
        }
    }

    if (gotError)
        return EXIT_SUCCESS;

    // Print bytes in structures before & after reversal.
    printf("Structure bytes before (1st line) & after (2nd line) reversal:\n\n");
    for (elemNo = 0; elemNo < (int)Elements(x); ++elemNo, putchar('\n'))
    {
        y[elemNo] = x[elemNo];
        ReverseMembersEndian(&y[elemNo]);
        printf("Element %d:\n", elemNo);
        printf("  ");
        cp = (UChar*)&x[elemNo];
        for (byteNo = 0; byteNo < sizeof(*x); ++byteNo)
            printf(" %02x", (unsigned)cp[byteNo]);
        printf("\n  ");
        cp = (UChar*)&y[elemNo];
        for (byteNo = 0; byteNo < sizeof(*y); ++byteNo)
            printf(" %02x", (unsigned)cp[byteNo]);
    }
    printf("\n\n"
        "PLEASE BE SURE YOU HAVE ANSWERED THE FOLLOWING QUESTIONS:\n"
        "   1. Were the results you got correct for your implementation?\n"
        "   2. How many padding bytes were in your structure?\n\n");

    return EXIT_SUCCESS;
}
#endif
