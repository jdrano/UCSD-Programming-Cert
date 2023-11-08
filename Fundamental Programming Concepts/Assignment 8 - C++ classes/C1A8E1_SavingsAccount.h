// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 8/27/23
// C1A8E1_SavingsAccount.h
// Win10
// Visual Studio 2022
// Contains member functions and variables for SavingsAccount object.

#ifndef C1A8E1_SAVINGSACCOUNT_H
#define C1A8E1_SAVINGSACCOUNT_H

#include <string>
#include <iostream>

class SavingsAccount    
{                       
private:
    int type_;
    std::string ownerName_;
    long IDnbr_;
    double balance_, closurePenaltyPercent_;

public:
    void GetInitialValues();
    
    inline void DisplayValues() const;
    
    inline double CalculatePenalty() const {
        const double PERCENT_OFFSET = 0.01;
        return balance_ * closurePenaltyPercent_ * PERCENT_OFFSET;
    };

};

inline void SavingsAccount::DisplayValues() const {
    std::cout << "\nAccount type: " << type_ 
        << "\nOwner Name: " << ownerName_
        << "\nID Number: " << IDnbr_
        << "\nAccount balance: " << balance_
        << "\nAccount closure penalty percent: " << closurePenaltyPercent_ 
        << "\n";
}

#endif // C1A8E1_SAVINGSACCOUNT_H