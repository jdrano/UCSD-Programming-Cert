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

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cfloat>
using namespace std;

#define Elements(A) (sizeof(A) / sizeof(*(A)))

float* SortValues(float* first, size_t elements);
float* GetValues(float* first, size_t elements);
static bool DisplayValues(float* first, size_t elements);

int main()
{
    constexpr size_t lengths[] = { 12, 9, 7 };

    for (size_t testIx = 0; testIx < Elements(lengths); ++testIx)
    {
        size_t elements = lengths[testIx];
        float* pRtn;

        // Allocate the array.
        float* arr = new (nothrow) float[elements];
        if (!arr)
        {
            cerr << "Error - ALLOCATION FAILED IN INSTRUCTOR DRIVER FILE.\n\n";
            continue;
        }

        const size_t halfway = elements / 2;

        // Initialize array.
        for (size_t ix = 0; ix < elements; ++ix)
            arr[ix] = (ix < halfway) ? FLT_MIN : FLT_MAX;

        pRtn = GetValues(arr + 1, elements - 2);
        if (pRtn != arr + 1)
            cerr << "Error - Unexpected pointer returned from GetValues.\n";

        if (arr[0] > FLT_MIN || arr[elements - 1] < FLT_MAX)
            cerr << "Error - Out-of-bounds array access in GetValues.\n";

        // Test that array values have changed.  This assumes FLT_MIN and FLT_MAX
        // are not input values.
        for (size_t ix = 1; ix < elements - 1; ++ix)
        {
            if (arr[ix] == ((ix < halfway) ? FLT_MIN : FLT_MAX))
            {
                cerr << "Error - GetValues did not store input values properly.\n";
                break;
            }
        }

        pRtn = SortValues(arr + 1, elements - 2);
        if (pRtn != arr + 1)
            cerr << "Error - Unexpected pointer returned from SortValues.\n";

        if (arr[0] > FLT_MIN || arr[elements - 1] < FLT_MAX)
            cerr << "Error - Out-of-bounds array access in SortValues.\n";

        DisplayValues(arr + 1, elements - 2);

        delete[] arr;
    }

    return EXIT_SUCCESS;
}

bool DisplayValues(float* first, size_t elements)
{
    bool badSortOrder = false, equalValueElements = true, badValue = false;
    float previousVal = *first, firstVal = *first;

    // For each element
    for (float* p = first, *end = &first[elements]; p < end; ++p)
    {
        cout << *p << '\n';

        if (*p == FLT_MIN || *p == FLT_MAX)
            badValue = true;

        if (p != first)                  // if not at the first element...
        {
            if (previousVal < *p)         // ...check sort order
                badSortOrder = true;
            // Insist that all elements cannot be the same.
            if (*p != firstVal)
                equalValueElements = false;
        }
        previousVal = *p;                // save this element
    }
    if (equalValueElements)
        badValue = true;

    if (badSortOrder && badValue)
        cerr << "Error - Element order and element value error.\n\n";
    else if (badSortOrder)
        cerr << "Error - Element order error.\n\n";
    else if (badValue)
        cerr << "Error - Element value error.\n\n";
    else
    {
        cout << "Element order is correct.\n\n";
        return true;
    }//badValue badSortOrder
    return false;
}
#endif
