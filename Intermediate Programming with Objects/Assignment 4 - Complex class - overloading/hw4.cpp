// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 10/18/23
// hw4.cpp
// Win10
// Visual Studio 2022
// Main file tests the Complex class which overloads >>,<<,+,-,==, and !-
// operators.

#include "Complex.h"
#include <iostream>
using namespace std;
using JoseMedrano::Complex;


int main() {
    // Testing constructors of varying inputs
    cout << "Creating and Printing Complex objects\n";
    Complex a(1, 1);
    cout << a << '\n';

    Complex b(-1, 1); 
    cout << b << '\n';

    Complex c(1, -1);
    cout << c << '\n';

    Complex d(-1, -1);
    cout << d << '\n';

    cout << '\n';

    // Testing overloaded +,- operators
    cout << "Testing overloaded '+' and '-' operators\n";
    Complex e = a + b;
    cout << "Complex e = " << a << " + " << b << '\n';
    cout << e << " = " << a + b << '\n';

    Complex f = d - b;
    cout << "Complex f = " << d << " - " << b << '\n';
    cout << f << " = " << d - b << '\n';

    // Testing overloaded ==,!= operators
    cout << "\nTesting equality comparisons\n";
    Complex a2(1, 1);
    bool aSame = a == a2;
    cout << a << " == " << a2 << " returns " << aSame << '\n';

    aSame = a != a2;
    cout << a << " != " << a2 << " returns " << aSame << '\n';

    // Testing >> operator
    cout << "Testing overloaded '>>' operator\n";

    cout << "Using input 5+3i\n";
    Complex test1;
    cin >> test1;
    cout << test1 << '\n';

    cout << "Using input -5+3i\n";
    Complex test2;
    cin >> test2;
    cout << test2 << '\n';

    return 0;
}