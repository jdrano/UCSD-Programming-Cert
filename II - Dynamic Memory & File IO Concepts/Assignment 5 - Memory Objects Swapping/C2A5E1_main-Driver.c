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
#include <string.h>

#define Elements(arrayDesig) (sizeof(arrayDesig)/sizeof((arrayDesig)[0]))

void SwapObjects(void* pa, void* pb, size_t size);

int main(void)
{
    // Create some test arrays whose elements will get swapped.
    int iArray[] = { 0x5555, 0xAAAA };
    int iArrayCopy[Elements(iArray)];
    struct xyz { char c; double d; };
    struct xyz sArray[] = { {'0', 1.234}, {'Z', 5.678} };
    struct xyz sArrayCopy[Elements(sArray)];

    // Copy initialized arrays into uninitialized arrays.
    memcpy((void*)iArrayCopy, (void*)iArray, sizeof iArray);
    memcpy((void*)&sArrayCopy, (void*)&sArray, sizeof sArray);

    // Swap elements in test arrays.
    SwapObjects((void*)&iArray[0], (void*)&iArray[1], sizeof * iArray);
    SwapObjects((void*)&sArray[0], (void*)&sArray[1], sizeof * sArray);

    // Test if swaps worked.
    if (iArray[0] != iArrayCopy[1] || iArray[1] != iArrayCopy[0] ||
        sArray[0].c != sArrayCopy[1].c || sArray[1].c != sArrayCopy[0].c ||
        sArray[0].d != sArrayCopy[1].d || sArray[1].d != sArrayCopy[0].d)
    {
        fprintf(stderr, "SwapObjects failed\n");
        return EXIT_FAILURE;
    }
    else
        printf("SwapObjects succeeded\n");

    return EXIT_SUCCESS;
}
#endif
