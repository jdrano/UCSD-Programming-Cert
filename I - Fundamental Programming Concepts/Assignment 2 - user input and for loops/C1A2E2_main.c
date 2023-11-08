// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 7/23/23
// C1A2E2_main.c
// Win10
// Visual Studio 2022
// Program takes in user_print to determine the number of steps to print.
// The steps are composed of a leading character on the end of the line and 
// filling characters in between.

#include <stdio.h>
#define LEADER_CHAR '^'
#define DIAGONAL_CHAR '$'
int main(void)
{
    int loops;
    
    printf("Enter any positive decimal integer value : ");
    scanf("%d", &loops);
    printf("\n");

    // Initial loop to place the diagonal characters
    for (int line_num = 0; line_num < loops; line_num++) {
        // Loop to print leader characters dependent on line number
        for (int num_of_chars = 0; num_of_chars < line_num; num_of_chars++) {
            printf("%c", LEADER_CHAR);
        }
        printf("%c\n", DIAGONAL_CHAR);
    }
    return 0;
}
