//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/17/24
// C2A2E1_CountIntBitsF.c
// Win10
// Visual Studio 2022
//
// Using bit shifting we can count how many bits are in this implementation's 
// version of int. We keep shifting until all the bits are gone leaving our
// int with a value of 0.
// 
// HW1 Question 1
// If ran on the same implementation the values produced by CountBitsM and
// countIntBitsF should be the same. They should be the same because if they 
// have the same implementation of byte size, then counting the individual bits
// and multiplying the number of bytes by bits will give the same answer.
//

int CountIntBitsF(void) {
    // Count the amount of bits we are shifting before we get 0
    int count = 0;
    for (unsigned int value = 1; value != 0; value <<= 1) {
        count++;
    }

    return count;
}
