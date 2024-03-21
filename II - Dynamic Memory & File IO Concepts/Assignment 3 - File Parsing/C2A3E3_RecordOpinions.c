//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/18/24
// C2A3E3_RecordOpinions.c
// Win10
// Visual Studio 2022
//
// This file contains a function, RecordOpinions, that takes user_input and 
// compiles it into a readable table.
//

#include <stdio.h>

#define BEST 0
#define WORST (-BEST)
#define CHOICES (BEST + BEST + 1)
#define TERMINATE 999
#define MIDPOINT (CHOICES / 2)
void RecordOpinions(void)
{
    int ratings[CHOICES] = {0};
    int *middle = &ratings[MIDPOINT];

    printf("Allowed ratings range from %d to %d, when ready to terminate enter "
        "%d.\n", BEST, WORST, TERMINATE);

    int user_rating = 0;
    // Take input until hitting invalid input
    for (;;) {
        printf("Enter rating: ");
        scanf("%d", &user_rating);

        // Increment valid entry in the table, or break
        if (WORST <= user_rating && user_rating <= BEST) {
            middle[user_rating]++;
        }
        // Check for invalid response that isn't the terminating key
        else if ((user_rating < WORST || BEST < user_rating) && 
            user_rating != TERMINATE) {
            printf("You have entered an invalid value. Enter a valid entry.\n");
        }
        else {
            break;
        }
    }

    // Determine which message to show user for invalid input
    if (user_rating == TERMINATE) {
        printf("You have entered the terminating value.\n");
    }

    // Prints the table
    for (int curr_rating = 0; curr_rating < CHOICES; curr_rating++) {
        // Prints top line of the table
        if (curr_rating == 0) {
            printf("%6s %8s\n", "Rating", "Quantity");
            printf("%6s %8s\n", "------", "--------");
        }

        printf("%6d %8d\n", WORST + curr_rating, ratings[curr_rating]);
    }
}
