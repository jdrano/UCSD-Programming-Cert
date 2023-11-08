// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/01/23
// C1A4E1_main.c
// Win10
// Visual Studio 2022
// This program takes 2 user inputted double values and prints out the 
// minimum and maximum between the values using functions not defined
// in the main file.

#include <stdio.h>
double ComputeMinimum(double value_one, double value_two);
double ComputeMaximum(double value_one, double value_two);

int main(void)
{
    double value_one, value_two;

    printf("Enter two space-separated decimal values : ");
    scanf("%lf %lf", &value_one, &value_two);
    printf("\nComputeMinimum(%f, %f) returned %f\n"
        "ComputeMaximum(%f, %f) returned %f\n", value_one, value_two, 
        ComputeMinimum(value_one, value_two), value_one, value_two,
        ComputeMaximum(value_one, value_two));

    return 0;
}
