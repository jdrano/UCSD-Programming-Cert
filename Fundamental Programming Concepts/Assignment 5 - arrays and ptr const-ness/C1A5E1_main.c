// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/09/23
// C1A5E1_main.c
// Win10
// Visual Studio 2022
// This program takes input data and, if it fits within the specified range,
// adds them to an array with the full table printed whenever all shoppers
// have been asked for a range.

#include <stdio.h>
#define SHOPPERS 3
#define BEST (-3)
#define WORST (-3)
#define CHOICES (BEST - WORST + 1)
#define MAX_ERRORS 3 
#define Q_SPACING 12
#define R_SPACING 6

int main(void)
{
    int ratings[CHOICES] = {0};
    int errors = 0;

    printf("The allowed ratings range is between values %d and %d.\n"
        "The max amount of errors that can be made is/are %d\n"
        "Num of choices is %d\n"
        , WORST, BEST, MAX_ERRORS, CHOICES);

    // Get input for all shoppers.
    for (int curr_shopper = 0; curr_shopper < SHOPPERS;) {
        int rating;
        printf("Enter a rating : ");
        scanf("%d", &rating);

        // Reset current iteration if input out of range
        if (rating < WORST || rating > BEST) {
            errors++;
            printf("Input out of range.\n");

            // Go to table if max errors reached.
            if (errors == MAX_ERRORS) {
                printf("Max errors reached.\n");
                break;
            }
            continue;
        }

        ratings[rating - WORST]++;   
        curr_shopper++;
        errors = 0;
    }

    printf("Rating    Quantity\n");
    printf("------    --------\n");

    // Prints table
    for (int line = 0; line < CHOICES; line++) {
        printf("%*d%*d\n", R_SPACING, BEST - line, Q_SPACING, 
            ratings[CHOICES - line - 1]);
    }

    return 0;
}
