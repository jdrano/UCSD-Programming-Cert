//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/27/24
// C2A7E4_ReverseEndian.c
// Win10
// Visual Studio 2022
//
// Changes the endian of any given scalar ptr
//

#include <stddef.h>

#define HALF 2

void *ReverseEndian(void *ptr, size_t size)
{
    char *bytePtr = (char *)ptr;
    // Read half of the bytes and swap them in reverse order
    for (size_t curr_byte = 0; curr_byte < size / HALF; curr_byte++) 
    {
        char temp = bytePtr[curr_byte];
        bytePtr[curr_byte] = bytePtr[size - 1 - curr_byte];
        bytePtr[size - 1 - curr_byte] = temp;
    }

    return ptr;
}
