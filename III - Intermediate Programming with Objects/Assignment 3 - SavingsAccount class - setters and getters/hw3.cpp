// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 10/17/23
// hw3.cpp
// Win10
// Visual Studio 2022
// Main file tests multiple constructors of my SavingsAccount class along with
// accessors and mutators. Also tests edge cases for incorrect inputs.

#include "SavingsAccount.h"
#include <iostream>
using namespace std;
using JoseMedrano::SavingsAccount;


int main() {
    
    // Constructor testing
    cout << "---TESTING CONSTRUCTOR---\n";
    SavingsAccount jose(1);
    cout << "Current savings balance is : " << jose.getSavingsBalance() 
        << ".\n";

    // Testing invalid constructor
    cout << "\n\nTESTING INVALID CONSTRUCTOR---\n";
    SavingsAccount negative(-1);

    // Adjusting balance via interest rate on base object
    cout << "\n\n---TESTING INTEREST RATE ON BASE OBJECT---\n";
    cout << "Savings before applying monthly interest is : " << 
        jose.getSavingsBalance() << ".\n";
    jose.applyMonthlyInterest();
    cout << "Savings after applying monthly interest is : " <<
        jose.getSavingsBalance() << ".\n";

    // Changing annual interest rate
    jose.setAnnualInterestRate(1);

    // Adjusting balance via interest rate after changing annual interest
    cout << "\n\n---TESTING INTEREST RATE ON CHANGED ANNUAL INTEREST---\n";
    cout << "Savings before applying monthly interest is : " <<
        jose.getSavingsBalance() << ".\n";
    jose.applyMonthlyInterest();
    cout << "Savings after applying monthly interest is : " <<
        jose.getSavingsBalance() << ".\n";

    // Test illegal interest rate
    cout << "\n\n---TESTING ILLEGAL ANNUAL INTEREST RATE---\n";
    jose.setAnnualInterestRate(-1);

    return 0;
}