// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/07/23
// hw6.cpp
// Win10
// Visual Studio 2022


#include "Array.h"
#include <iostream>
using namespace std;
using JoseMedrano::Array;


int main() {
    const int size = 5;

    // Create an Array using the default constructor 
    Array<int, size> starting; 

    // Modify all the elements of an Array using the L-value
    // subscript operator
    for (int index = 0; index < size; index++) {
        starting[index] = index;
    }

    // Output all the elements of an Array using the R-value
    // subscript operator
    cout << "Starting array has : ";
    for (int index = 0; index < size; index++) {
        cout << starting[index] << " ";
    }

    cout << '\n';

    // Create a const Array from another Array using the copy constructor 
    const Array<int, size> copy(starting);
    cout << "Copy array has : ";
    for (int index = 0; index < size; index++) {
        cout << copy[index] << " ";
    }

    cout << '\n';

    // Assign an Array to an existing Array using the copy assignment operator
    const Array<int, size> assignment = copy;
    cout << "Assignment array has : ";
    for (int index = 0; index < size; index++) {
        cout << assignment[index] << " ";
    }

    cout << '\n';

    // Compare two Arrays using the equality operator
    cout << "Comparing equality for starting to copy : ";
    cout << (starting == copy);
    cout << '\n';

    // Compare two Arrays using the inequality operator
    cout << "Comparing inequality for starting to copy : ";
    cout << (starting != copy);
    cout << '\n';

    // Demonstrate an invalid_argument exception being thrown and caught when 
    // the L - value subscript operator is accessed with an index < 0
    cout << "Attempting lValue invalid access, < 0\n";
    try {
        starting[-1] = 0;
    }
    catch (invalid_argument &e) {
        cerr << "Exception caught : " << e.what() << '\n';
    }

    // Demonstrate an invalid_argument exception being thrown and caught when 
    // the L - value subscript operator is accessed with an index >= SIZE
    cout << "Attempting lValue invalid access, >= SIZE\n";
    try {
        starting[10] = 0;
    }
    catch (invalid_argument &e) {
        cerr << "Exception caught : " << e.what() << '\n';
    }

    // Demonstrate an invalid_argument exception being thrown and caught when 
    // the R - value subscript operator is accessed with an index < 0 
    // (you can force the R - value subscript operator to be called by accessing
    // an element in the const Array).
    cout << "Attempting rValue invalid access, < 0\n";
    try {
        int a = assignment[-1];
    }
    catch (invalid_argument &e) {
        cerr << "Exception caught : " << e.what() << '\n';
    }

    // Demonstrate an invalid_argument exception being thrown and caught when
    // the R - value subscript operator is accessed with an index >= SIZE(you 
    // can force the Rvalue subscript operator to be called by accessing an 
    // element in the const Array).
    cout << "Attempting rValue invalid access, >= SIZE\n";
    try {
        int a = assignment[10];
    }
    catch (invalid_argument &e) {
        cerr << "Exception caught : " << e.what() << '\n';
    }


    return 0;
}