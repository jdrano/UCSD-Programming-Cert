// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/15/23
// C1A6E1_main.c
// Win10
// Visual Studio 2022
// This program prompts the user to input a string and prints out the length
// using strlen and our version MyStrlen. Inlcude prototype of MyStrlen where 
// the definition can be found separately in the project.

#include <stdio.h>
#include <string.h>

#define LENGTH 81

size_t MyStrlen(const char *s1);

int main(void)
{
    size_t length, my_Length;
    char input[LENGTH];

    printf("Enter a string : ");

    // Assigns user-input to the input variable
    fgets(input, LENGTH, stdin);

    // Replaces newline character with null character
    input[strcspn(input, "\n")] = '\0';

    length = strlen(input);
    printf("strlen(\"%s\") returned %zu\n", input, length);

    my_Length = MyStrlen(input);
    printf("MyStrlen(\"%s\") returned %zu\n", input, my_Length);

    return 0;
}
