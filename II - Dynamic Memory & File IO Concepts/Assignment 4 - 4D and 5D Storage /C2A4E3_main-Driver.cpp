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
#include <iostream>

extern const int DIM0, DIM1, DIM2, DIM3;
extern float*** pointerArray4D[];

int main()
{
    int value;

    // Store all values.
    value = 0;
    for (int ix0 = 0; ix0 < DIM0; ++ix0)
        for (int ix1 = 0; ix1 < DIM1; ++ix1)
            for (int ix2 = 0; ix2 < DIM2; ++ix2)
                for (int ix3 = 0; ix3 < DIM3; ++ix3)
                    pointerArray4D[ix0][ix1][ix2][ix3] = float(value++);

    // Test all stored values.
    value = 0;
    for (int ix0 = 0; ix0 < DIM0; ++ix0)
        for (int ix1 = 0; ix1 < DIM1; ++ix1)
            for (int ix2 = 0; ix2 < DIM2; ++ix2)
                for (int ix3 = 0; ix3 < DIM3; ++ix3)
                    if (pointerArray4D[ix0][ix1][ix2][ix3] != value++)
                    {
                        std::cerr << "Error at: ptr4D[" << ix0 << "][" << ix1 << "][";
                        std::cerr << ix2 << "][" << ix3 << "]\n";
                        return EXIT_FAILURE;
                    }

    std::cout << "Assignment 4 Exercise 3: No errors detected!\n";
    return EXIT_SUCCESS;
}
#endif
