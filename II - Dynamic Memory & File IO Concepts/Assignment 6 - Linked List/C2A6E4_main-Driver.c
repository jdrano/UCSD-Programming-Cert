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

#include "C2A6E4_List-Driver.h"

#define FILENAME "TestFile1.txt"

FILE* OpenFile(const char* fileName);
List* CreateList(FILE* fp);
List* PrintList(const List* head);
void FreeList(List* head);

int main(void)
{
    FILE* fp = OpenFile(FILENAME);
    List* head = CreateList(fp);

    fclose(fp);
    FreeList(PrintList(head));

    return EXIT_SUCCESS;
}
#endif
