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

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

#include <stdio.h>
#include <string.h>

#define TEST_CHAR_ARRAY_SIZE 128
#define TEST_STRING_COUNT 2

size_t StrToUpper(char destination[], const char source[]);

/*
* Test: StrToUpper
*/
int main(void)
{
    int tests = 0, errors = 0;

    int whichStrings;
    char copiedString[TEST_CHAR_ARRAY_SIZE];
    size_t originalLength, copiedLength;

    const struct
    {
        const char* original, * upper;
    } TEST_STRINGS[TEST_STRING_COUNT] =
    { { "Hello world 123!@#", "HELLO WORLD 123!@#" },{ "", "" } };

    for (whichStrings = 0; whichStrings < TEST_STRING_COUNT; ++whichStrings)
    {
        const char* original = TEST_STRINGS[whichStrings].original;
        const char* upper = TEST_STRINGS[whichStrings].upper;

        strcpy(&copiedString[strlen(TEST_STRINGS[whichStrings].original)],
            "_MISSING_NULL_TERMINATOR_");

        // Test converting a string to uppercase.
        originalLength = strlen(original);
        copiedLength = StrToUpper(copiedString, original);
        ++tests;
        if (copiedLength != originalLength)
        {
            fprintf(stderr, "***ERROR*** StrToUpper: The value "
                "returned by the function, \"%d\", is not the same "
                "as the length of original string \"%d\".\n\n",
                (int)copiedLength, (int)originalLength);
            ++errors;
        }
        ++tests;
        if (strcmp(copiedString, upper))
        {
            fprintf(stderr, "***ERROR*** StrToUpper: The copied string, "
                "\"%s\", is not as expected: \"%s\".\n\n",
                copiedString, upper);
            ++errors;
        }
    }

    const char* plural = errors != 1 ? "s" : "";
    if (errors)
        fputc('\n', stderr);
    fprintf(stderr, "C2A1E4: %d tests %d error%s.\n",
        tests, errors, plural);

    return 0;
}
#endif
