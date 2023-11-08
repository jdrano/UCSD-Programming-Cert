// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/15/23
// C1A6E2_main.c
// Win10
// Visual Studio 2022
// Takes two input data strings and compares to see if they are the same string.
// Once using strcmp and once using my own function MyStrcmp.

#include <stdio.h>
#include <string.h>

#define LENGTH 81

int MyStrcmp(const char *s1, const char *s2);

int main(void)
{
    char word1[LENGTH], word2[LENGTH];

    printf("Enter 2 space-separated strings\nWord One : ");
    // Assign user input to word 1
    fgets(word1, LENGTH, stdin);
    printf("Word Two : ");
    // Assign user input to word 2
    fgets(word2, LENGTH, stdin);

    word1[strcspn(word1, "\n")] = '\0'; // Replace newline char with null
    word2[strcspn(word2, "\n")] = '\0'; // Replace newline char with null
    
    printf("strcmp(\"%s\", \"%s\") returned %d\n", 
        word1, word2, strcmp(word1, word2));

    printf("MyStrcmp(\"%s\", \"%s\") returned %d\n",
        word1, word2, MyStrcmp(word1, word2));

    return 0;
}
