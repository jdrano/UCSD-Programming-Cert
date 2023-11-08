// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/16/23
// C1A6E3_main.c
// Win10
// Visual Studio 2022
// Takes input data of a string with max length 256, then creates a substring
// where the starting point and length is also given as input data.

#include <stdio.h>
#include <string.h>

#define LENGTH 256

char *GetSubstring(const char source[], int start, int count, char result[]);

int main(void)
{
    int start, count;
    char source[LENGTH], result[LENGTH];

    printf("Enter any sequence of 0 or more arbitrary printable characters : ");
    fgets(source, LENGTH, stdin);
    source[strcspn(source, "\n")] = '\0'; // Replace newline char with null

    printf("Enter, space-separated, start index and character count : ");
    scanf("%d %d", &start, &count);

    printf("\"%s\", %d, %d, extracts \"%s\"\n", 
        source, start, count, GetSubstring(source, start, count, result));

    return 0;
}
