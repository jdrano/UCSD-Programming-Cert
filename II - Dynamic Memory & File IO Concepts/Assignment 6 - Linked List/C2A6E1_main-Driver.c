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

int (*GetPrintfPointer(void))(const char* format, ...);
int (*GetPutsPointer(void))(const char* str);

int main(void)
{
    int rtnPrintf =
        GetPrintfPointer()("Testing %s %x %d %o\n", "\"printf\"", 25, 25, 25);

    int rtnPuts =
        GetPutsPointer()("Testing \"puts\"");

    printf("printf returned %d; puts returned %d\n", rtnPrintf, rtnPuts);

    return EXIT_SUCCESS;
}
#endif
