//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 177752, Prof. Mitchell
// 02/10/24
// BigInt.h
// Win10
// Visual Studio 2022
//
// Header for our BigInt class
//

#include <iostream>
#include <string>
using namespace std;

namespace Project1
{
    class BigInt
    {
        friend ostream &operator<<(ostream&, const BigInt&);
        friend istream &operator>>(istream&, BigInt&);
        friend bool operator==(const BigInt&, const BigInt&);
        friend bool operator!=(const BigInt&, const BigInt&);
        friend bool operator<(const BigInt&, const BigInt&);
        friend bool operator<=(const BigInt&, const BigInt&);
        friend bool operator>(const BigInt&, const BigInt&);
        friend bool operator>=(const BigInt&, const BigInt&);
        

    public:
        BigInt();
        BigInt(const BigInt&);
        BigInt(long long);
        // Throws invalid_argument if string malformed (contains anything
        // other than a legally formatted number)
        BigInt(const string&);

        const BigInt& operator=(const BigInt&);
        const BigInt& operator+=(const BigInt&);
        const BigInt& operator-=(const BigInt&);
        BigInt operator+(const BigInt&);
        BigInt operator-(const BigInt&);
        

    private:
        BigInt addition(const BigInt&, const BigInt&);
        BigInt subtraction(const BigInt&, const BigInt&);

        void validStringCheck(const string&);
        string simplifyString(string);
        bool illegalCharCheck(char);
        string value;
        bool positive;
    };
}