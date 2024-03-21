//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/02/24
// C2A4E1_WorkerFunction.cpp
// Win10
// Visual Studio 2022
//
// This file contains the function definition for WorkerFunction which calls
// the other functions that actually operate on the 4D array.
//

#include "C2A4E1_ArraySize.h"

void RandomizeArray(float testArray[DIM0][DIM1][DIM2][DIM3]);

void ComputeAverages(float testArray[DIM0][DIM1][DIM2][DIM3],
    float *nestedAvg, float *linearAvg);

void WorkerFunction(float *nestedAvg, float *linearAvg) {
    float testArray[DIM0][DIM1][DIM2][DIM3];
    RandomizeArray(testArray);
    ComputeAverages(testArray, nestedAvg, linearAvg);
}