//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 177752, Prof. Mitchell
// 02/05/24
// Minimized_CheckingAccount.cpp
// Win10
// Visual Studio 2022
//
// The file gives an example of the Pimpl idiom. Moved all of the private 
// fields into an imple struct of the CheckingAccount class.
//

#include "Minimized_CheckingAccount.h"

// System includes
#include <list>
#include <string>
#include <vector>

// User includes
#include "Check.h"

struct CheckingAccount::CheckingAccount_Imple {
    long accountNumber_;
    double balance_;
    string firstName_;
    string lastName_;
    vector<double> deposits_;
    vector<double> withdrawals_;
    list<Check> checks_;
};