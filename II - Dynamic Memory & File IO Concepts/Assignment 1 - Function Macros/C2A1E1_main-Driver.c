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
#include "C2A1E1_Macros.h"

//
// Test: Macros
//
int main(void)
{
    int tests = 0, errors = 0;
    size_t count;
    double result;
    double arr[] = { 5.5, 6, 7, 8, 9 }, * p = arr + 2;
    short arr1[] = { 7, 8, 9 };

    ++tests;
    result = 2 * Product(5.5 + 4, 3.5 + 2);
    if (result != 104.5)
    {
        fprintf(stderr,
            "***ERROR*** \"Product\" macro:\n"
            "   2// Product(5.5 + 4, 3.5 + 2)\n"
            "should evaluate to 104.5 but it evaluated to %g when your macro "
            "was used.\n\n", result);
        ++errors;
    }

    ++tests;
    result = sizeof Product(5, 3.5 + 2);
    if (result != sizeof(double))
    {
        fprintf(stderr,
            "***ERROR*** \"Product\" macro:\n"
            "   sizeof Product(5, 3.5 + 2)\n"
            "should evaluate to %d but it evaluated to %g when your macro "
            "was used.\n\n", (int)sizeof(double), result);
        ++errors;
    }

    ++tests;
    result = Negate(5.5 + 4);
    if (result != -9.5)
    {
        fprintf(stderr,
            "***ERROR*** \"Negate\" macro:\n"
            "   Negate(5.5 + 4)\n"
            "should evaluate to -9.5 but it evaluated to %g when your macro "
            "was used.\n\n", result);
        ++errors;
    }

    ++tests;
    result = Negate(2)[p];
    if (result != 5.5)
    {
        fprintf(stderr,
            "***ERROR*** \"Negate\" macro: For the following declarations,\n"
            "   double arr[] = {5.5, 6, 7, 8, 9}, *p = arr + 2;\n"
            "Negate(2)[p] should evaluate to 5.5 but it evaluated to %g when "
            "your macro was used.\n\n",
            result);
        ++errors;
    }

    ++tests;
    count = Elements(arr);
    if (count != 5)
    {
        fprintf(stderr,
            "***ERROR*** \"Elements\" macro: For the following declaration,\n"
            "   double arr[] = {5.5, 6, 7, 8, 9};\n"
            "Elements(arr) should evaluate to 5 but it evaluated to %d when "
            "your macro was used.\n\n", (int)count);
        ++errors;
    }

    ++tests;
    count = Elements(arr1);
    if (count != 3)
    {
        fprintf(stderr,
            "***ERROR*** \"Elements\" macro: For the following declaration,\n"
            "   short arr1[] = {7, 8, 9};\n"
            "Elements(arr1) should evaluate to 3 but it evaluated to %d when "
            "your macro was used.\n\n", (int)count);
        ++errors;
    }

    ++tests;
    count = Elements("Hello");
    if (count != 6)
    {
        fprintf(stderr,
            "***ERROR*** \"Elements\" macro: For the following array,\n"
            "   \"Hello\"\n"
            "Elements(\"Hello\") should evaluate to 6 but it evaluated to %d when "
            "your macro was used.\n\n", (int)count);
        ++errors;
    }

    const char* plural = errors != 1 ? "s" : "";
    if (errors)
        fputc('\n', stderr);
    fprintf(stderr, "C2A1E1: %d tests %d error%s.\n",
        tests, errors, plural);

    if (arr1[0] + tests == arr1[0] - tests)    // silence "unused" warnings
        return 0;

    return 0;
}
#endif
