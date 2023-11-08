// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 10/10/23
// hw2.cpp
// Win10
// Visual Studio 2022
// Main file tests multiple constructors of my Date class along with
// accessors and mutators. Also tests edge cases for incorrect inputs.

#include "Date.h"
#include <iostream>
using namespace std;
using JoseMedrano::Date;

// Test months
const int FEB = 2;
const int APRIL = 4;
const int DEC = 12;

// Test day
const int NINE = 9;

// Test years
const int BORN_YR = 1998;
const int CURR_YR = 2023;

// Illegal Day/Month combos
const int THIRTY_DAYS = 30;
const int THIRTY_ONE_DAYS = 31;
const int THIRTY_TWO_DAYS = 32;


int main() {
    // Date default constructor test
    cout << "Testing default constructor\n";
    Date test;
    test.display();
    cout << "\n";

    // Date creation
    cout << "Testing param constructor\n";
    Date jose(DEC, NINE, BORN_YR);
    jose.display();
    cout << "\n";

    // Test legal and illegal month choices
    cout << "Testing setMonth\n";
    jose.setMonth(1);
    jose.display();
    jose.setMonth(-1);
    jose.display();
    cout << "\n";

    // Test legal and illegal day choices
    cout << "Testing setDay\n";
    jose.setDay(1);
    jose.display();
    jose.setDay(-1);
    jose.display();
    cout << "\n";

    // Test legal and illegal year choices
    cout << "Testing setYear\n";
    jose.setYear(1);
    jose.display();
    jose.setYear(-1);
    jose.display();
    cout << "\n";

    // Testing illegal day and month combos
    cout << "Testing illegal day and month combo\n";
    Date wrong(FEB, THIRTY_DAYS, CURR_YR);
    wrong.display();
    cout << "\n";
    Date wrongTwo(APRIL, THIRTY_ONE_DAYS, CURR_YR);
    wrong.display();
    cout << "\n";
    Date wrongThree(DEC, THIRTY_TWO_DAYS, CURR_YR);
    wrong.display();
    cout << "\n";

    return 0;
}