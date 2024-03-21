//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/02/24
// C2A4E1_ComputeAverages.cpp
// Win10
// Visual Studio 2022
//
// The file contains a function that uses two different types of array 
// accessing to calculate the sum.
//

#include "C2A4E1_ArraySize.h"

void ComputeAverages(float testArray[DIM0][DIM1][DIM2][DIM3], float *nestedAvg, 
    float *linearAvg)
{
    // Initialize values to 0
    *nestedAvg = 0;
    *linearAvg = 0;
    // Nested access
    for (int ix0 = 0; ix0 < DIM0; ix0++) {
        for (int ix1 = 0; ix1 < DIM1; ix1++) {
            for (int ix2 = 0; ix2 < DIM2; ix2++) {
                for (int ix3 = 0; ix3 < DIM3; ix3++) {
                    *nestedAvg += testArray[ix0][ix1][ix2][ix3];
                }
            }
        }
    }
    *nestedAvg /= NUM_OF_ELEM;

    // Linear access using walking pointer
    for (float *ptr = (float *)testArray; ptr < (float *)testArray + (DIM0 *
        DIM1 * DIM2 * DIM3); ++ptr)  {
        *linearAvg += *ptr;
    }
    *linearAvg /= NUM_OF_ELEM;
}