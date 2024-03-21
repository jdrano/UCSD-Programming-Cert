//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/10/24
// C2A1E3_FindFirstInt.c
// Win10
// Visual Studio 2022
//
// Finds and returns a pointer to the first matching value in the array.
//

#include <stdlib.h>

int *FindFirstInt(const int *ptr, size_t count, int value) {
    // Search through array for first matching int.
    for (size_t curr_int = 0; curr_int < count; curr_int++) {
        // Matching value found.
        if (ptr[curr_int] == value) {
            return (int *)&ptr[curr_int];
        }
    }
    return NULL;
}
