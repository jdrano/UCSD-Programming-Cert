// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/14/23
// C1A6E1_MyStrlen.c
// Win10
// Visual Studio 2022
// MyStrlen recreates the strlen function taking a const char ptr and returning
// the length of the string

#include <stddef.h>

size_t MyStrlen(const char *s1)
{
    const char * const START = s1;

    // increment through string until hitting a newline character
    while (*s1 != '\0') {
        s1++;
    }

    return s1 - START;
}
