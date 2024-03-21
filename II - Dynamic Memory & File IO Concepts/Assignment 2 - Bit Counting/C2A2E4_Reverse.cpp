//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/18/24
// C2A2E4_Reverse.cpp
// Win10
// Visual Studio 2022
//
// This file contains 2 functions. 1, to check if the character in our ifstream
// is a valid to print character or if it should be handled by our main driver.
// 2, a function that is recursively calling itself so that we print out the 
// last characters before our invalid characters.
//

#include <fstream>
#include <iostream>
using namespace std;

const int REC_CAP_FIRST = 1;
const int REC_CAP_SECOND = 3;

inline bool isSeparator(char current_char) {
    // Test if current_char is a valid separator
    if (current_char == '.' || current_char == '?' || current_char == '!' ||
        current_char == ',' || current_char == ':' || current_char == ';' ||
        current_char == EOF) {
        return true;
    }

    // Test for if current_char is a whitespace char
    if (isspace(current_char)) {
        return true;
    }
    return false;
}

//---------------------------------------------------------------------
// SUMMARY
//      Recursively reads one character at a time from the text file in inFile 
//      until a separator is read. Then any non - separator characters that were
//      read are displayed in reverse order with the last and next to next to 
//      last characters capitalized. Finally, the separator is returned to the 
//      calling function. Reverse neither reverses nor prints separators but 
//      merely returns them. The code in the instructor - supplied driver file 
//      is responsible for printing each returned separator.
//
// RESOURCES
//      None
//
// PARAMETERS
//      inFile 
//          a reference to an ifstream object representing a text file open in 
//          a readable text mode.
//      level
//          recursive level of this function call : 1 = > 1st call, 
//          2 = > 2nd call, etc.
//      
// RETURNS
//      int
//          The current separator.
//---------------------------------------------------------------------
int
Reverse(ifstream &inFile, const int level) {
    char current_char;
    inFile.get(current_char);

    // Test case for when we reach the EOF so we a return special character
    if (inFile.eof()) {
        return -1;
    }

    // End recursive loop when separator found
    if (isSeparator(current_char)) {
        return current_char;
    }
    else {
        // Recursively continue down the stream for the next char
        int thisSeparator = Reverse(inFile, level + 1);
        if (level == REC_CAP_FIRST || level == REC_CAP_SECOND) {
            cout.put((char)toupper(current_char));
        }
        else {
            cout.put(current_char);
        }
        return thisSeparator;
    }
}