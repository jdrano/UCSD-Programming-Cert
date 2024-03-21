//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/10/24
// C2A1E4_StrToUpper.c
// Win10
// Visual Studio 2022
//
// This file acts as a copy string function in C, while copying the capitalized
// versions of the characters.
//

#include <stdio.h>
#include <ctype.h>

size_t StrToUpper(char *copy, const char *src) {
    const char *tmp = src;

    // Copy capitalized characters into the replacement string until the end
    while (*tmp != '\0') {
        *copy++ = (char)toupper(*tmp++);
    }
    *copy = '\0';

    return tmp - src;
}
