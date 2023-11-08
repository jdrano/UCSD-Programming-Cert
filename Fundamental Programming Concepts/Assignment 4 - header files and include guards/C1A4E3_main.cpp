// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 8/1/23
// C1A4E3_main.cpp
// Win10
// Visual Studio 2022
// The program prints a given char an X amount of times on Y
// amount of lines. The char, X, and Y are taken from user input.

#include <iostream>
using namespace std;

void PrintLines(int value = 'Z', int length = 1, int line_num = 1);

int main()
{
    const int MAX_STEPS = 2;

    // Repeat interaction process until reaching max number of iterations
    for (int step = 0; step < MAX_STEPS; step++) {
        char charValue;
        int charCount, lineCount;

        cout << "Enter, space-separated, a char value, "
            "how many times to print, "
            "and how many lines of it to print : ";

        cin >> charValue >> charCount >> lineCount;

        PrintLines(charValue, charCount, lineCount);
        PrintLines(charValue, charCount);
        PrintLines(charValue);
        PrintLines();
    }

    return 0;
}
