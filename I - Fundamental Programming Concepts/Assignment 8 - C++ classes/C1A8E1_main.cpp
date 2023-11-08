// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/27/23
// C1A8E1_main.cpp
// Win10
// Visual Studio 2022
// This file creates a SavingsAccount object, then prompts the user to fill in
// the member variables of said object. Displays values associated with object.

#include <iostream>
#include "C1A8E1_SavingsAccount.h"
using namespace std;

int main()
{
    // Create object jim
    SavingsAccount Jim;
    Jim.GetInitialValues();
    Jim.DisplayValues();
    cout << "Account closure penalty: " << Jim.CalculatePenalty() << '\n';

    return 0;
}
