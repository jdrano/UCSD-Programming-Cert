// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 8/1/23
// C1A4E3_PrintLines.cpp
// Win10
// Visual Studio 2022
// Prints out a char given from the value parameter a length amount of times.
// Then repeats that process a line_num of times.

#include <iostream>
using namespace std;

void PrintLines(int value, int length, int line_num)
{
    // Keep printing new lines until reaching row max from line_num
    for (int starting_line = 0; starting_line < line_num; starting_line++) {
        // Prints a char given from value parameter a length amount of times.
        for (int char_num = 0; char_num < length; char_num++) {
            cout << (char)value;
        }
        cout << "\n";
    }
}