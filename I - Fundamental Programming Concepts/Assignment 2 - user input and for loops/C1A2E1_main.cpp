// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 7/23/23
// C1A2E1_main.cpp
// Win10
// Visual Studio 2022
// 
// Program assumes user input is a valid lowercase character and prints out the
// uppercase version of it using ASCII conversion.
// 
// Questions
// 1. The user enters anything other than a lowercase character.
//          When a character is entered that is not a lowercase character a 
//          seemingly random character is outputted, but really the 
//          character that is outputted is the character with ab ASCII value
//          that is 32 smaller than the input from the user.
// 2. The user precedes the input character with a whitespace.
//          When using the cin.get(char), the first initial character given
//          from the user is what's stored in the argument (in our case 
//          user_input). So we're printing ' '(32 ASCII - 32 which is 0 which 
//          is the ASCII value for NULL.

#include <iostream>

using namespace std;

int main()
{
    const int CONVERTER = 'a' - 'A';
    char user_input;
    cout << "Enter any character : ";
    cin.get(user_input);
    cout << "The uppercase equivalent of '" << user_input << "' is '" << 
        (char)(user_input - CONVERTER) << "' (decimal value = " << 
        user_input - CONVERTER << ")\n";

    return 0;
}