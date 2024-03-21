//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 177752, Prof. Mitchell
// 02/05/24
// Minimized_CheckingAccount.h
// Win10
// Visual Studio 2022
//
// Header file of an optimized CheckingAccount. Got rid of unnecessary user
// includes and changed <ostrea> to the forward declaration <iosfwd>. And 
// adding the Pimpl idiom. 
//

// CheckingAccount.h
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

// System includes
#include <iosfwd>

using namespace std;

// User includes
#include "BankAccount.h" // class BankAccount
class Check;

class CheckingAccount : public BankAccount
{
public:
    CheckingAccount(long accountNumber,
        double initialBalance,
        const string& firstName,
        const string& lastName);
    ~CheckingAccount();
    double getBalance() const;
    void depositCheck(const Check&);
    void depositCash(double);
    void withdrawCash(double);

protected:
    void processAccount();

private:
    struct CheckingAccount_Imple;
    CheckingAccount_Imple *pimple;
};
ostream& operator<<(ostream &o, const CheckingAccount&) {
    return o;
}
#endif