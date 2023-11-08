// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 7/25/23
// C1A3E2_main.cpp
// Win10
// Visual Studio 2022
// This program takes in user_input and prints out the value in reverse 
// while taking into consideration if the value was positive or not.

#include <iostream>
using namespace std;

int main()
{
    const int RADIX = 10;
    int user_input;
    bool positive;
  
    cout << "Enter any decimal integer value : ";
    cin >> user_input;
    cout << "\n";

    positive = user_input >= 0;

    cout << "\"" << user_input << "\" in reverse is \"";

    // Changes input to positive so that the algorithm works accordingly
    if (!positive) {
        user_input = -user_input;
    }

    // Keeps track of falling digits by / RADIX until single digit
    do {
        cout << user_input % RADIX;
        user_input /= RADIX;
    } while (user_input != 0);

    // Places final digit and a '-' depending if initial input was pos/neg.
    if (positive) {
        cout << "\"\n";
    }
    else {
        cout << "-\"\n";
    }

    return 0;
}
