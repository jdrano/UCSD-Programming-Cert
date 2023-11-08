// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/07/23
// Array.h
// Win10
// Visual Studio 2022
// Array class and member data.
#ifndef JOSEMEDRANO_ARRAY_H
#define JOSEMEDRANO_ARRAY_H

#include <stdexcept>
#include <iostream>
using namespace std;

namespace JoseMedrano {
    template <typename ElemType, int SIZE>
    class Array {
    public:
        // Default cstr
        Array()  {
            // Initialize empty array
            for (int curr_num = 0; curr_num < SIZE; curr_num++) {
                elements[curr_num] = 0;
            }
        }

        // Copy cstr
        Array(const Array<ElemType, SIZE> &copy) {
            // Deep copy array values
            for (int curr_num = 0; curr_num < SIZE; curr_num++) {
                this->elements[curr_num] = copy.elements[curr_num];
            }
        }

        // Assignment overload
        Array<ElemType, SIZE> &operator=(const Array<ElemType, SIZE> &source) {
            // Check for self-assignment
            if (this == &source) {
                return *this;
            }

            // Deep copy array values
            for (int curr_num = 0; curr_num < SIZE; curr_num++) {
                this->elements[curr_num] = source.elements[curr_num];
            }

            return *this;
        }

        // Equality overload
        bool operator==(const Array<ElemType, SIZE> &other) {
            // Check every index for equal value
            for (int curr_num = 0; curr_num < SIZE; curr_num++) {
                if (this->elements[curr_num] != other.elements[curr_num]) {
                    return false;
                }
            }

            return true;
        }

        // Inequality overload
        bool operator!=(const Array<ElemType, SIZE> &other) {
            // Check every index for unequal value
            for (int curr_num = 0; curr_num < SIZE; curr_num++) {
                if (this->elements[curr_num] == other.elements[curr_num]) {
                    return false;
                }
            }

            return true;
        }

        // lValue subscript operator
        ElemType& operator[](int index) {
            if (index < 0 || index >= SIZE) {
                throw std::invalid_argument("Index out of range");
            }
            return elements[index];
        }

        //rValue subscript operator
        const ElemType& operator[](int index) const {
            if (index < 0 || index >= SIZE) {
                throw std::invalid_argument("Index out of range");
            }
            return elements[index];
        }

    private:
        ElemType elements[SIZE];
    };
}

#endif