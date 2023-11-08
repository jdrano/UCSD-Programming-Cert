// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 7/25/23
// C1A3E3_main.cpp
// Win10
// Visual Studio 2022
// This assignment takes in an octal user_input and prints what their input was
// along with the input printed out in text form.

#include <iostream>
using namespace std;

int main()
{
    const int RADIX = 8;

    bool first_word = true;
    int user_input;
    int divisor = 1;
    int dividend;

    cout << oct << "Enter any octal integer value : ";
    cin >> oct >> user_input;

    // Change input to positive, while printing the '-' sign
    if (user_input < 0) {
        user_input = -user_input;
        cout << "\"-" << user_input << "\" in words is \"minus ";
    }
    else {
        cout << "\"" << user_input << "\" in words is \"";
    }
    
    // Multiply divisor by the radix until divisor reaches most sig digit 
    for (dividend = user_input; dividend > RADIX - 1; dividend /= RADIX) {
        divisor *= RADIX;
    }

    dividend = user_input;
    // Continue to receive falling_digit using divisor then print using switch
    do {
        int falling_digit = dividend / divisor;

        if (first_word) {
            first_word = false;
        }
        else {
            cout << " ";
        }

        // Prints out name of digit given from falling_digit
        switch (falling_digit) {
            case 0:
                cout << "zero";
                break;
            case 1:
                cout << "one";
                break;
            case 2:
                cout << "two";
                break;
            case 3:
                cout << "three";
                break;
            case 4:
                cout << "four";
                break;
            case 5:
                cout << "five";
                break;
            case 6:
                cout << "six";
                break;
            case 7:
                cout << "seven";
                break;
            default:
                cout << "you broke it somehow";
                break;
        }
        falling_digit *= divisor;
        dividend -= falling_digit;
        divisor /= RADIX;

    // Check to see if we can continue taking the MSD from the dividend
    } while (divisor != 0);

    cout << "\"\n";
    return 0;
}
