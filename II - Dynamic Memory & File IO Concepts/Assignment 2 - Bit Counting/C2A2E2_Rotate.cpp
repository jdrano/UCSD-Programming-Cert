//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/17/24
// C2A2E2_Rotate.cpp
// Win10
// Visual Studio 2022
//
// This file rotates the bits of an unsigned param based on param count 
// rotations.
//

int CountIntBitsF();

unsigned Rotate(unsigned object, int count) {
    // No rotate case
    if (count == 0) {
        return object;
    }
    int bitAmount = CountIntBitsF();
    count %= bitAmount;

    // Right rotation
    if (count > 0) {
        // Rotates object's bits to the right and replaces 1st bit
        object = (object >> count) | (object << (bitAmount - count));
    }
    // Left rotation
    else {
        count = -count;
        object = (object << count) | object >> (bitAmount - count);
    }
    return object;
}