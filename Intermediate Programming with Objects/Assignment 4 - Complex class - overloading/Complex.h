// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 10/18/23
// Complex.h
// Win10
// Visual Studio 2022
// Complex class and member data.

#ifndef JOSEMEDRANO_COMPLEX_H
#define JOSEMEDRANO_COMPLEX_H

#include <iostream>
using namespace std;

namespace JoseMedrano {
    class Complex {

        // Overloading >> and << operators
        friend istream &operator>>(istream &in, Complex &value);
        friend ostream &operator<<(ostream &out, const Complex &value);

    public:
        // Constructors
        Complex();
        Complex(double real, double imaginary);

        // Operator Overloads
        Complex operator+(const Complex &other) const;
        Complex operator-(const Complex &other) const;
        bool operator==(const Complex &other) const;
        bool operator!=(const Complex &other) const;
        
    private:
        double real, imaginary;
    };
}
#endif