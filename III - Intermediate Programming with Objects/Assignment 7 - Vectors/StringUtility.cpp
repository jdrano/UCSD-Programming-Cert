// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/14/23
// StringUtility.cpp
// Win10
// Visual Studio 2022
// Definitions for StringUtility class.

#include "StringUtility.h"
#include <iostream>
string
JoseMedrano::StringUtility::join(const vector<string> &strings, char delimiter)
{
    string joined = "";

    // Add delimiter to the end of every string
    for (int curr_string = 0; curr_string < strings.size(); curr_string++) {
        joined += strings[curr_string] + delimiter;
    }

    return joined;
}

vector<string> 
JoseMedrano::StringUtility::reverse(const vector<string> &strings)
{
    vector<string> reversed;

    // Start reversal list from the back of the vector
    for (int string_pos = strings.size() - 1; string_pos >= 0; string_pos--) {
        string curr_string = "";

        // Start reversal string from the back of the string
        for (int curr_char = strings[string_pos].size() - 1; 
            curr_char >= 0; curr_char--) 
        {
            curr_string += strings[string_pos][curr_char];
        }
        reversed.push_back(curr_string);
    }

    return reversed;
}

vector<string>
JoseMedrano::StringUtility::combine(const vector<string> &left, 
    const vector<string> &right) {
    
    vector<string> combined;
    bool leftGreater;

    // Check to determine which algorithm to use
    if (left.size() > right.size()) {
        leftGreater = true;
    }
    else {
        leftGreater = false;
    }

    // Adjust algorithm in mind of which parameter is greater to not access any
    // null spaces.
    if (leftGreater) {
        int curr_pos = 0;
        for (; curr_pos < right.size(); curr_pos++) {
            combined.push_back(left[curr_pos] + right[curr_pos]);
        }

        for (; curr_pos < left.size(); curr_pos++) {
            combined.push_back(left[curr_pos]);
        }
    }
    else {
        int curr_pos = 0;
        for (; curr_pos < left.size(); curr_pos++) {
            combined.push_back(left[curr_pos] + right[curr_pos]);
        }

        for (; curr_pos < right.size(); curr_pos++) {
            combined.push_back(right[curr_pos]);
        }
    }

    return combined;
}

vector<string> 
JoseMedrano::StringUtility::leftPad(const vector<string> &strings, char pad) {
    int maxLength = 0;
    int tempLength = 0;
    vector<string> padded;

    // Find the largest length string in the vector
    for (int curr_string = 0; curr_string < strings.size(); curr_string++) {
        tempLength = strings[curr_string].size();
        if (maxLength < tempLength) {
            maxLength = tempLength;
        }
    }

    // Adjust pad length to each word and add to vector
    for (int curr_string = 0; curr_string < strings.size(); curr_string++) {
        string tempString = "";
        tempLength = strings[curr_string].size();

        for (int difference = maxLength - tempLength; difference > 0; 
            difference--) {

            tempString += pad;
        }

        padded.push_back(tempString + strings[curr_string]);
    }

    return padded;
}