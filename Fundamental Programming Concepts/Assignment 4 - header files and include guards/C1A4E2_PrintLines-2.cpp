// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 8/1/23
// C1A4E2_PrintLines-2.cpp
// Win10
// Visual Studio 2022
// Prints out a char given from the value parameter a length amount of times.

#include <iostream>
using namespace std;

void PrintLines(int value, int length)
{
    // Print value char until reaching length parameter
    for (int char_num = 0; char_num < length; char_num++) {
        cout << (char)value;
    }
    cout << "\n";
}