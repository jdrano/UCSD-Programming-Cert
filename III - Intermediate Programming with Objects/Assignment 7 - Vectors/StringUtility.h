// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/14/23
// StringUtility.h
// Win10
// Visual Studio 2022
// StringUtility class and member data. 

#ifndef JOSEMEDRANO_STRINGUTILITY_H
#define JOSEMEDRANO_STRINGUTILITY_H

#include <string>
using std::string;

#include <vector>
using std::vector;

namespace JoseMedrano {

    /***************************************************************************
    * StringUtility class delcarations
    ***************************************************************************/
    class StringUtility {

    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Concatenate the strings from the strings parameter together 
        //      placing the delimiter character in between each pair of strings.
        //      The resulting string should be returned.
        //
        // RESOURCES
        //      None.
        //
        // PARAMETERS
        //      strings
        //          Set of strings to be conjoined.
        //      delimiter
        //          The character that will being the conjoining char between 
        //          the strings.
        //
        // RETURNS
        //      The conjoined string.
        //---------------------------------------------------------------------
        string join(const vector<string> &strings, char delimiter);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns a vector containing the strings from the strings 
        //      parameter in reversed order and with the contents of each 
        //      string reversed.
        //
        // RESOURCES
        //      None.
        //
        // PARAMETERS
        //      strings
        //          Set of strings to be reversed.
        //
        // RETURNS
        //      A vector in reverse order of the strings parameter.
        //---------------------------------------------------------------------
        vector<string> reverse(const vector<string> &strings);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Return a vector containing every string from left concatenated 
        //      with every string from right.
        //
        // RESOURCES
        //      None.
        //
        // PARAMETERS
        //      &left
        //          Strings that make up the left side of the new string in the
        //          vector.
        //      &right
        //          Strings that make up the right side of the new string in the
        //          vector.
        //
        // RETURNS
        //      A vector that has a combined set of each string in each 
        //      corresponding vector placement.
        //---------------------------------------------------------------------
        vector<string> combine(const vector<string> &left, 
            const vector<string> &right);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Return a vector containing each string from the strings 
        //      parameter left-padded with the pad character so that each 
        //      resulting string has a length equal to the longest 
        //      original string.
        //
        // RESOURCES
        //      None.
        //
        // PARAMETERS
        //      &strings
        //          Strings used to make up the newly padded vector<string>
        //      pad
        //          The character that will be added to each string to create 
        //          equal length strings.
        //
        // RETURNS
        //      A vector with padded out strings.
        //---------------------------------------------------------------------
        vector<string> leftPad(const vector<string> &strings, char pad);
    };
    
}
#endif