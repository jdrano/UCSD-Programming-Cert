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
#include <limits.h>

#define INIT_ARRAY_COUNT 128

void* ResizeAlloc(void* pOld, size_t newSize, size_t oldSize);

//
// Test: ResizeAlloc
//
int main(void)
{
    int tests = 0, errors = 0;

    signed char* initArray, * initArray1;
    signed char* cp;
    signed char value;
    int ix;

    ++tests;
#if 0
#define INIT_ARRAY_COUNT_FAIL UINT_MAX
    // Check for intentional allocation failure.
    initArray = ResizeAlloc(NULL, INIT_ARRAY_COUNT_FAIL, 0);
    if (initArray)
    {
        fprintf(stderr, "***ERROR*** ResizeAlloc: Array allocation "
            "failure not detected when size was too large.\n\n");
        free(initArray);
        ++errors;
    }
#endif

    // Check for intentional allocation rejection.
    ++tests;
    initArray = ResizeAlloc(NULL, 0, 0);
    if (initArray)
    {
        fprintf(stderr, "***ERROR*** ResizeAlloc: Array allocation "
            "rejection not detected when 2nd argument was 0.\n\n");
        free(initArray);
        ++errors;
    }

    // Check for successful allocation.
    ++tests;
    initArray = ResizeAlloc(NULL, INIT_ARRAY_COUNT, 0);
    if (!initArray)
    {
        fprintf(stderr, "***ERROR*** ResizeAlloc: Array allocation "
            "failed.\n\n");
        ++errors;
    }

    // Check for correct write/read.
    ++tests;
    value = SCHAR_MIN;
    // Initialize all elements.
    for (cp = initArray; cp < initArray + INIT_ARRAY_COUNT; ++cp)
        *cp = value++;
    value = SCHAR_MIN;
    ix = 0;
    // Test all elements.
    for (cp = initArray; cp < initArray + INIT_ARRAY_COUNT; ++cp)
    {
        if (*cp != value++)
        {
            fprintf(stderr, "***ERROR*** ResizeAlloc: Incorrect value at "
                "element %d.\n\n", ix);
            ++errors;
        }
        ++ix;
    }

    // Check for correct size increase.
    ++tests;
    initArray1 =
        ResizeAlloc(initArray, INIT_ARRAY_COUNT * 2, INIT_ARRAY_COUNT);
    // Initialize upper elements.
    value = SCHAR_MAX;
    ++tests;
    for (cp = initArray1 + INIT_ARRAY_COUNT;
        cp < initArray1 + INIT_ARRAY_COUNT * 2;
        ++cp)
    {
        *cp = value--;
    }

    value = SCHAR_MIN;
    // Test lower elements.
    ix = 0;
    for (cp = initArray1; cp < initArray1 + INIT_ARRAY_COUNT; ++cp)
    {
        if (*cp != value++)
        {
            fprintf(stderr, "***ERROR*** ResizeAlloc: Incorrect value at "
                "element %d.\n\n", ix);
            ++errors;
        }
        ++ix;
    }

    value = SCHAR_MAX;
    // Test upper elements.
    ix = INIT_ARRAY_COUNT / 2;
    for (cp = initArray1 + INIT_ARRAY_COUNT;
        cp < initArray1 + INIT_ARRAY_COUNT * 2;
        ++cp)
    {
        if (*cp != value--)
        {
            fprintf(stderr, "***ERROR*** ResizeAlloc: Incorrect value at "
                "element %d.\n\n", ix);
            ++errors;
        }
        ++ix;
    }

    // Check for correct size reduction.
    ++tests;
    initArray =
        ResizeAlloc(initArray1, INIT_ARRAY_COUNT / 2, INIT_ARRAY_COUNT * 2);

    value = SCHAR_MIN;
    // Test 1/2 of lower elements.
    ix = 0;
    for (cp = initArray; cp < initArray + INIT_ARRAY_COUNT / 2; ++cp)
    {
        if (*cp != value++)
        {
            fprintf(stderr, "***ERROR*** ResizeAlloc: Incorrect value at "
                "element %d.\n\n", ix);
            ++errors;
        }
        ++ix;
    }

    free(initArray);

    const char* plural = errors != 1 ? "s" : "";
    if (errors)
        fputc('\n', stderr);
    fprintf(stderr, "C2A1E5: %d tests %d error%s.\n",
        tests, errors, plural);

    return 0;
}
#endif
