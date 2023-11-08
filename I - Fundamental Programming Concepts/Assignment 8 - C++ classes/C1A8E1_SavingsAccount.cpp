// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/27/23
// C1A8E1_SavingsAccount.cpp
// Win10
// Visual Studio 2022
// This function takes in user input to create a SavingsAccount object.
// Then prints out relative information about the object.

#include "C1A8E1_SavingsAccount.h"
#include <string>
#include <iostream>
using namespace std;

void SavingsAccount::GetInitialValues() {
    cout << "Enter Account Type: ";
    cin >> type_;

    cout << "Enter Owner Name: ";
    cin >> ws; // disregard '\n' char from previous cin read
    getline(cin, ownerName_);

    cout << "Enter ID number: ";
    cin >> IDnbr_;

    cout << "Enter Account Balance: ";
    cin >> balance_;

    cout << "Enter Account closure penalty percent: ";
    cin >> closurePenaltyPercent_;
}