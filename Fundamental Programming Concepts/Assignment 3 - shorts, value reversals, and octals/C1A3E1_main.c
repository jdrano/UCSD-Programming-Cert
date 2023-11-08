// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 7/25/23
// C1A3E1_main.c
// Win10
// Visual Studio 2022
// Program takes in user_input to determine how many cubic sums to create
// and then lists them in a dual column table.

#include <stdio.h>
#define NBR_SPACING 3
#define CUBIC_SACING 10

int main(void)
{
    int user_input;
    short cubic_sum = 0;

    printf("Enter any integer value >= 0 : ");
    scanf("%d", &user_input);
    printf(" nbr     cubic sum\n"
        "----------------\n");

    user_input++; // Necessary so the loop goes up to literal input

    for (int curr_num = 0; curr_num < user_input; curr_num++) {
        cubic_sum += (short)(curr_num * curr_num * curr_num);

        printf("%*d%*d\n", NBR_SPACING, curr_num, CUBIC_SACING, cubic_sum);
    }

    return 0;
}
