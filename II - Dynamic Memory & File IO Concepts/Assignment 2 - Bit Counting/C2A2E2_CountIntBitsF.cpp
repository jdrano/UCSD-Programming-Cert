//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/17/24
// C2A2E2_CountIntBitsF.cpp
// Win10
// Visual Studio 2022
//
// Using bit shifting we can count how many bits are in this implementation's 
// version of int. We keep shifting until all the bits are gone leaving our
// int with a value of 0.
//

int CountIntBitsF() {
    // Count the amount of bits we are shifting before we get 0
    int count = 0;
    for (unsigned int value = 1; value != 0; value <<= 1) {
        count++;
    }

    return count;
}
