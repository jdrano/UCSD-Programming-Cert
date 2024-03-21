#ifndef C2A6E4_LIST_DRIVER_H
#define C2A6E4_LIST_DRIVER_H

/***    YOU DO NEED TO UNDERSTAND THE CODE IN THIS FILE TO WRITE YOURS    ***/

/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/
/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/
/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/

//****************************************************************************
// Everything in this file was written to help test/verify your code and must
// not be altered in any way.  Do not rename this file or copy anything from
// it into your file(s).  This file does not necessarily represent good coding
// technique, proper formatting/style, or meet the requirements your code must
// meet.  You DO need to understand the code in this file to write yours.
//
// You may #include this file in your file(s) as necessary.
//****************************************************************************

// Format of each list node...
typedef struct List
{
    struct List* next;   // pointer to the next list node
    char* str;           // pointer to the string represented
    int count;           // # of occurrences of this string
} List;

#endif
