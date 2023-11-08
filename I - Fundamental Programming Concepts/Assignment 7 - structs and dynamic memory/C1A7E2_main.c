// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/22/23
// C1A7E2_main.c
// Win10
// Visual Studio 2022
// This program takes user input of food with their respective weight and 
// calories, then displays them into a table. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LUNCH_QTY 5
#define FOOD_OFFSET 2
#define TABLE_SPACING 15
#define MAX_NAME_LENGTH 20

int main(void)
{
    // Defining the Food struct to have a name, weight, and calories
    struct Food {
        char *name;
        int weight, calories;
    } lunches[LUNCH_QTY] = {{"apple", 4, 100}, {"salad", 2, 80}};

    printf("Enter a whitespace-separated name, weight, and calories of a food "
        "in that order on the same line. The name must not contain a whitespace"
        "\n");

    // Fill in the rest of lunches array starting at the first empty spot.
    for (int curr_food = FOOD_OFFSET; curr_food < LUNCH_QTY; curr_food++) {
        char name[MAX_NAME_LENGTH];
        int weight, calories;

        printf("Enter: ");
        scanf("%19s %d %d", name, &weight, &calories);

        // Count num of chars in given name until hitting null terminator.
        size_t char_in_name = strlen(name);

        // Allocate exact amount of memory needed for given name.
        // Pre-increment char_in_name for null terminator.
        char *name_data = (char *)malloc(++char_in_name);

        // Safety check for failed memory allocation. Returns error code if so.
        if (name_data != NULL) {
            memcpy(name_data, name, char_in_name);
        }
        else {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }

        lunches[curr_food].name = name_data;
        lunches[curr_food].calories = calories;
        lunches[curr_food].weight = weight;
    }

    printf("%-*s%*s%*s", TABLE_SPACING, "Food", TABLE_SPACING,
        "Weight", TABLE_SPACING, "Calories\n");
    printf("%*s", TABLE_SPACING, "------------------------------"
        "--------------\n");

    // Print the values of the lunch array into a table.
    for (int food = 0; food < LUNCH_QTY; food++) {
        printf("%-*s%*d%*d\n", TABLE_SPACING, lunches[food].name, TABLE_SPACING,
            lunches[food].weight, TABLE_SPACING, lunches[food].calories);

        // Free all dynamically allocated memory.
        if (food >= FOOD_OFFSET) {
            free(lunches[food].name);
        }
    }

    return 0;
}
