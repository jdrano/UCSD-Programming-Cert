// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 7/23/23
// C1A2E3_main.cpp
// Win10
// Visual Studio 2022
// Program takes in user_print to determine the number of steps to print.
// The steps are composed of a leading character on the end of the line and 
// filling characters in between.

#include <iostream>
using namespace std;

int main()
{
    constexpr char LEADER_CHAR = '^';
    constexpr char DIAGONAL_CHAR = '$';
    int loops;

    cout << "Enter any positive decimal integer value : ";
    cin >> loops;
    cout << "\n";

    // Initial loop to place the diagonal characters
    for (int line_num = 0; line_num < loops; line_num++) {
        // Loop to print leader characters dependent on line number
        for (int num_of_chars = 0; num_of_chars < line_num; num_of_chars++) {
            cout << LEADER_CHAR;
        }
        cout << DIAGONAL_CHAR << "\n";
    }
    
    
    return 0;
}