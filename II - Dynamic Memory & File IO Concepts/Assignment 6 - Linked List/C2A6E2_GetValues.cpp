//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/17/24
// C2A6E2_GetValues.cpp
// Win10
// Visual Studio 2022
//
// Contains a function that intitializes the float array with values from
// user-input.
//

#include <cstddef>
#include <iostream>
using namespace std;

float *GetValues(float *first, size_t elements)
{
    float *initial = first;
    cout << "Enter " << elements << " space-separated values: ";

    // For every element we add to the array
    while (elements--)
    {
        cin >> *first++;
    }

    return initial;
}