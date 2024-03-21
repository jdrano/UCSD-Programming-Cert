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

#define INT_TEST_VALUE_COUNT 10
#define INT_TEST_VALUE_TO_FIND1 (-10)
#define INT_TEST_VALUE_TO_FIND1_INDEX 1
#define INT_TEST_VALUE_TO_FIND2 65534

int* FindFirstInt(const int* ptr, size_t count, int value);

//
// Test: FindFirstInt
//
int main(void)
{
    int tests = 0, errors = 0;

    const int intTestValues[INT_TEST_VALUE_COUNT] =
    { 300, -10, -66, 10, -10, 23, 65535 };
    int* pFoundInt;

    ++tests;
    // Look for a value that exists.
    pFoundInt = FindFirstInt(intTestValues, INT_TEST_VALUE_COUNT,
        INT_TEST_VALUE_TO_FIND1);
    if (pFoundInt != intTestValues + INT_TEST_VALUE_TO_FIND1_INDEX)
    {
        fprintf(stderr,
            "***ERROR*** FindFirstInt: Existing value not found.\n\n");
        ++errors;
    }
    ++tests;
    // Look for a value that doesn't exist.
    pFoundInt = FindFirstInt(intTestValues, INT_TEST_VALUE_COUNT,
        INT_TEST_VALUE_TO_FIND2);
    if (pFoundInt != NULL)
    {
        fprintf(stderr, "***ERROR*** FindFirstInt: Non-existant value didn't "
            "cause a null pointer return.\n\n");
        ++errors;
    }

    const char* plural = errors != 1 ? "s" : "";
    if (errors)
        fputc('\n', stderr);
    fprintf(stderr, "C2A1E3: %d tests %d error%s.\n",
        tests, errors, plural);

    return 0;
}
#endif
