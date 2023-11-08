// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 10/17/23
// SavingsAccount.h
// Win10
// Visual Studio 2022
// SavingsAccount class and member data.

#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

namespace JoseMedrano
{
    class SavingsAccount
    {
    public:
        // Constructors
        SavingsAccount(double savingsBalance);

        // Accessors
        double getSavingsBalance() const;

        // Mutators
        void applyMonthlyInterest();
        static void setAnnualInterestRate(double newInterestRate);
        

    private:
        double savingsBalance;
        static double annualInterestRate;
    };
}

#endif