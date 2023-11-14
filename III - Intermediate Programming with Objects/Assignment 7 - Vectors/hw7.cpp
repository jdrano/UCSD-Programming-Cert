// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/14/23
// hw7.cpp
// Win10
// Visual Studio 2022

#include <iostream>
#include "StringUtility.h"
using namespace std;
using namespace JoseMedrano;


int main() {
    StringUtility stringUtil;

    // Test join function
    vector<string> testJoin {"The", "quick", "brown", "fox", "jumps", "over",
        "the", "lazy", "dog"};
    char delim = ',';
    cout << stringUtil.join(testJoin, delim) << '\n';

    // Test reverse function
    vector<string> testReverse {"The", "quick", "brown", "fox", "jumps",
        "over", "the", "lazy", "dog"};
    vector<string> reversed = stringUtil.reverse(testReverse);
    for (int curr_string = 0; curr_string < testReverse.size(); curr_string++) {
        cout << reversed[curr_string] + ',';
    }
    cout << '\n';

    // Test combined function
    vector<string> left {"Mr.", "Mrs."};
    vector<string> right {"Jones", "Smith", "Williams"};
    vector<string> combined = stringUtil.combine(left, right);
    for (int curr_string = 0; curr_string < combined.size(); curr_string++) {
        cout << combined[curr_string] + ',';
    }
    cout << '\n';


    // Test leftPad function
    vector<string> padMe {"The", "quick", "brown", "fox", "jumps", "over", 
        "the", "lazy", "dog"};
    char pad = '*';
    vector<string> padded = stringUtil.leftPad(padMe, pad);
    for (int curr_string = 0; curr_string < padded.size(); curr_string++) {
        cout << padded[curr_string] + ',';
    }
    return 0;
}