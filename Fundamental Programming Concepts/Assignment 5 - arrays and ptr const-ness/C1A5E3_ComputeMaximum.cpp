// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/14/23
// C1A5E3_ComputeMaximum.cpp
// Win10
// Visual Studio 2022
// Compares 2 values from given input and returns the pointer of higher value.

double *ComputeMaximum(const double *value_one, const double *value_two)
{
    return (double *)((*value_one > *value_two) ? value_one : value_two);
}
