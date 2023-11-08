// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 10/18/23
// Complex.cpp
// Win10
// Visual Studio 2022
// Definitions for Complex class.

#include "Complex.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Constructors
JoseMedrano::Complex::Complex() {
    this->real = 0;
    this->imaginary = 0;
}

JoseMedrano::Complex::Complex(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

// ----------Operator Overloads----------

// Overloading '+'
JoseMedrano::Complex
JoseMedrano::Complex::operator+(const Complex &other) const {
    double newReal = this->real + other.real;
    double newImaginary = this->imaginary + other.imaginary;

    return Complex(newReal, newImaginary);
}

// Overloading '-'
JoseMedrano::Complex
JoseMedrano::Complex::operator-(const Complex &other) const {
    double newReal = this->real - other.real;
    double newImaginary = this->imaginary - other.imaginary;

    return Complex(newReal, newImaginary);
}

// Overloading '=='
bool
JoseMedrano::Complex::operator==(const Complex &other) const {
    if (this->real == other.real && this->imaginary == other.imaginary) {
        return true;
    }
    else {
        return false;
    }
}

// Overloading '!='
bool
JoseMedrano::Complex::operator!=(const Complex &other) const {
    if (this->real != other.real || this->imaginary != other.imaginary) {
        return true;
    }
    else {
        return false;
    }
}

// Overloading the '<<'
ostream&
JoseMedrano::operator<<(ostream &out, const Complex &value) {
    out << value.real;

    // Add '+' if the imaginary value is positive
    if (value.imaginary >= 0) {
        out << '+' << value.imaginary << 'i';
    }
    else {
        out << value.imaginary << 'i';
    }

    return out;
}

// Overloading the '>>'
istream&
JoseMedrano::operator>>(istream &in, Complex &value) {
    string total, real, imaginary;
    int operands = 0;
    bool change = false;

    in >> total;

    // Check how many operands are given in the input
    for (int i = 0; i < total.size(); i++) {
        if (total[i] == '+' || total[i] == '-') {
            operands++;
        }
    }

    // if real value is positive
    if (operands == 1) {
        for (int i = 0; i < total.size(); i++) {
            if (total[i] == '+' || total[i] == '-') {
                change = true;
            }
            if (!change) {
                real += total[i];
            }
            else {
                imaginary += total[i];
            }
        }

        value.real = stod(real);
        value.imaginary = stod(imaginary);
    }

    // if real value is negative
    else {

        // Skip first entry so we can reuse positive algorithm
        for (int i = 1; i < total.size(); i++) {
            if (total[i] == '+' || total[i] == '-') {
                change = true;
            }
            if (!change) {
                real += total[i];
            }
            else {
                imaginary += total[i];
            }
        }

        value.real = -stod(real);
        value.imaginary = stod(imaginary);
    }

    return in;
}