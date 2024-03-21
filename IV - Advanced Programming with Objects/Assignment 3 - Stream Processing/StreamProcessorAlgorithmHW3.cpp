//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 177752, Prof. Mitchell
// 01/28/24
// StreamProcessorAlgorithmHW3.cpp
// Win10
// Visual Studio 2022
//
// Contains class definitions for SteamProcessorAlgorithm and its derived 
// classes UppercasingPSA and DigitStrippingPSA.
//

#include <sstream>
#include <iostream>
using namespace std;

/******************************************************************************
* StreamProcessorAlgorithm Class Definition
******************************************************************************/
class StreamProcessorAlgorithm
{
public:
    StreamProcessorAlgorithm(istream& in, ostream& out) : in_(in), out_(out)
    {

    }

    virtual ~StreamProcessorAlgorithm()
    {

    }


    void process()
    {
        string current_strand;

        // Read all of the input stream
        while (in_ >> current_strand) {
            if (filterToken(current_strand)) {
                processToken(current_strand);
                out_ << current_strand;
            }
        }
    }

private:
    virtual bool filterToken(const string& token) const = 0;
    virtual void processToken(string& token) const = 0;
    istream& in_;
    ostream& out_;
};

/******************************************************************************
* UppercasingPSA Class
******************************************************************************/

class UppercasingPSA : public StreamProcessorAlgorithm
{
public:
    UppercasingPSA(istream& in, ostream& out)
        : StreamProcessorAlgorithm(in, out)
    {

    }
private:
    virtual bool filterToken(const string& token) const
    {
        return true;
    }

    virtual void processToken(string& token) const
    {
        // Change every char into an uppercased version if applicable
        for (int curr_char = 0; curr_char < token.size(); curr_char++) {
            token[curr_char] = toupper(token[curr_char]);
        }
    }
};

/******************************************************************************
* DigitStrippingPSA Class
******************************************************************************/

class DigitStrippingPSA : public StreamProcessorAlgorithm
{
public:
    DigitStrippingPSA(istream& in, ostream& out)
        : StreamProcessorAlgorithm(in, out)
    {

    }
private:
    virtual bool filterToken(const string& token) const
    {
        // Search for any char that is a digit
        for (int curr_char = 0; curr_char < token.size(); curr_char++) {
            if (isdigit(token[curr_char])) {
                return true;
            }
        }
        return false;
    }

    virtual void processToken(string& token) const
    {
        // Check if the token has any digits
        if (!filterToken(token)) {
            return;
        }
        
        string noNums;
        // Add nondigits to new string and assign new string to token
        for (int curr_char = 0; curr_char < token.size(); curr_char++) {
            if (isdigit(token[curr_char])) {
                continue;
            }
            else {
                noNums += token[curr_char];
            }
        }

        token = noNums;
    }
};