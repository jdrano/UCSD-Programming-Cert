//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/02/24
// C2A4E1_RandomizeArray.cpp
// Win10
// Visual Studio 2022
//
// The file contains a function that initializes the array with random values
// using srand and time.
//

#include <cstdlib>
#include <ctime>
using namespace std;

#include "C2A4E1_ArraySize.h"

void RandomizeArray(float testArray[DIM0][DIM1][DIM2][DIM3])
{
    srand((unsigned int)time(0));
    // Use walking ptr to set every value to random
    for (float *ptr = (float *)testArray; ptr < (float *)testArray + (DIM0 * 
        DIM1 * DIM2 * DIM3); ++ptr) {
        *ptr = (float)rand();
    }
}
