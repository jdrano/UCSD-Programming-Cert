// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 10/17/23
// SavingsAccount.cpp
// Win10
// Visual Studio 2022
// Definitions for SavingsAccount class.

#include <iostream>
#include "SavingsAccount.h"

using namespace std;

double JoseMedrano::SavingsAccount::annualInterestRate;
const double PERCENTAGE = 1.0/12.0;

// Constructor
JoseMedrano::SavingsAccount::SavingsAccount(double savingsBalance) {
    // Check for invalid input
    if (savingsBalance < 0.0) {
        cerr << "Balance cannot be negative. Setting balance to 0.\n";
        this->savingsBalance = 0.0;
    }
    else {
        this->savingsBalance = savingsBalance;
    }
}

// Access savingsBalance
double
JoseMedrano::SavingsAccount::getSavingsBalance() const {
    return this->savingsBalance;
}

// Applies the set monthly interest to the balance
void
JoseMedrano::SavingsAccount::applyMonthlyInterest() {
    this->savingsBalance += (this->savingsBalance * annualInterestRate 
        * PERCENTAGE);
    cout << "current savings : " << this->savingsBalance <<
        ".\ncurrent annual interest rate : " << annualInterestRate <<
        ".\napplying percentage is : " << PERCENTAGE << "\n";
}

// Changes the annual interest rate
void
JoseMedrano::SavingsAccount::setAnnualInterestRate(double newInterestRate) {
    // Check for illegal interest rate change
    if (newInterestRate < 0.0) {
        cerr << "Annual interest rate cannot be negative. Setting annual "
            "interest rate to 0.\n";
        annualInterestRate = 0.0;
    }
    else {
        annualInterestRate = newInterestRate;
    }
}