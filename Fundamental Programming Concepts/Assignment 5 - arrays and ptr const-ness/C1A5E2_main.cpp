// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/11/23
// C1A5E2_main.cpp
// Win10
// Visual Studio 2022
// This program takes 2 user inputted double values and prints out the 
// minimum and maximum between the values using functions not defined
// in the main file.

#include <iostream>
using namespace std;
double &ComputeMinimum(const double &value_one, const double &value_two);
double &ComputeMaximum(const double &value_one, const double &value_two);

int main()
{
    double value_one, value_two;

    cout << "Enter two space-separated decimal values : ";
    cin >> value_one >> value_two;

    // Use ComputeMinimum to print smaller value
    cout << "ComputeMinimum(" << value_one << ", " << value_two << 
        ") returned " << ComputeMinimum(value_one, value_two) << "\n";
    
    // Use ComputeMaximum to print larger value
    cout << "ComputeMaximum(" << value_one << ", " << value_two <<
        ") returned " << ComputeMaximum(value_one, value_two) << "\n";

    return 0;
}
