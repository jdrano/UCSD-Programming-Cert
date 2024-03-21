//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 177752, Prof. Mitchell
// 01/28/24
// JoseMedranoHW3.cpp
// Win10
// Visual Studio 2022
//
// Contains the testunit functions for StreamProcessorAlgorith and its derived
// classes.
//

#include <sstream>
#include <iostream>

using namespace std;

#include "StreamProcessorAlgorithmHW3.cpp"

void
testUppercasingPSA_EmptyString() 
{
    istringstream empty("");
    ostringstream out;

    UppercasingPSA test(empty, out);
    test.process();

    if (out.str() != "") {
        clog << "testUpperCasingPSA_EmptyString FAILED: Expected empty string "
            << " instead saw " << out.str();
    }
    else {
        clog << "testUpperCasingPSA_EmptyString PASSED";
    }
    clog << '\n';
}

void
testUppercasingPSA_LowerToUpper()
{
    istringstream lower("abcdef");
    ostringstream out;

    UppercasingPSA test(lower, out);
    test.process();

    if (out.str() != "ABCDEF") {
        clog << "testUpppercasingPSA_LowerToUpper FAILED: Expected string \""
            << "ABCDEF\" instead saw " << out.str();
    }
    else {
        clog << "testUpppercasingPSA_LowerToUpper PASSED";
    }
    clog << '\n';
}

void
testUppercasingPSA_Upper()
{
    istringstream upper("ABCDEF");
    ostringstream out;

    UppercasingPSA test(upper, out);
    test.process();

    if (out.str() != "ABCDEF") {
        clog << "testUpppercasingPSA_Upper FAILED: Expected string \""
            << "ABCDEF\" instead saw " << out.str();
    }
    else {
        clog << "testUpppercasingPSA_Upper PASSED";
    }
    clog << '\n';
}

void
testUppercasingPSA_Mixed()
{
    istringstream mixed("aBcDeF");
    ostringstream out;

    UppercasingPSA test(mixed, out);
    test.process();

    if (out.str() != "ABCDEF") {
        clog << "testUpppercasingPSA_Mixed FAILED: Expected string \""
            << "ABCDEF\" instead saw " << out.str();
    }
    else {
        clog << "testUpppercasingPSA_Mixed PASSED";
    }
    clog << '\n';
}

void
testUppercasingPSA_NonAlphabet()
{
    istringstream nonalpha("aBc431");
    ostringstream out;

    UppercasingPSA test(nonalpha, out);
    test.process();

    if (out.str() != "ABC431") {
        clog << "testUpppercasingPSA_NonAlphabet FAILED: Expected string \""
            << "ABC431\" instead saw " << out.str();
    }
    else {
        clog << "testUpppercasingPSA_NonAlphabet PASSED";
    }
    clog << '\n';
}

void testUppercasingPSA()
{
    testUppercasingPSA_EmptyString();
    testUppercasingPSA_LowerToUpper();
    testUppercasingPSA_Upper();
    testUppercasingPSA_Mixed();
    testUppercasingPSA_NonAlphabet();
}

void testDigitStrippingPSA_EmptyString()
{
    istringstream empty("");
    ostringstream out;

    DigitStrippingPSA test(empty, out);
    test.process();

    if (out.str() != "") {
        clog << "testDigitStrippingPSA_EmptyString FAILED: "
            "Expected empty string " << " instead saw " << out.str();
    }
    else {
        clog << "testDigitStrippingPSA_EmptyString PASSED";
    }
    clog << '\n';
}

void testDigitStrippingPSA_OnlyDigits()
{
    istringstream digits("12345");
    ostringstream out;

    DigitStrippingPSA test(digits, out);
    test.process();

    if (out.str() != "") {
        clog << "testDigitStrippingPSA_OnlyDigits FAILED: "
            "Expected empty string " << " instead saw " << out.str();
    }
    else {
        clog << "testDigitStrippingPSA_OnlyDigits PASSED";
    }
    clog << '\n';
}

void testDigitStrippingPSA_NoDigits()
{
    istringstream digits("ABCDEF");
    ostringstream out;

    DigitStrippingPSA test(digits, out);
    test.process();

    if (out.str() != "") {
        clog << "testDigitStrippingPSA_NoDigits FAILED: "
            "Expected string ABCDEF" << " instead saw " << out.str();
    }
    else {
        clog << "testDigitStrippingPSA_NoDigits PASSED";
    }
    clog << '\n';
}

void testDigitStrippingPSA_MixedDigits()
{
    istringstream digits("A1B2CD4EF");
    ostringstream out;

    DigitStrippingPSA test(digits, out);
    test.process();

    if (out.str() != "ABCDEF") {
        clog << "testDigitStrippingPSA_MixedDigits FAILED: "
            "Expected string ABCDEF" << " instead saw " << out.str();
    }
    else {
        clog << "testDigitStrippingPSA_MixedDigits PASSED";
    }
    clog << '\n';
}

void testDigitStrippingPSA()
{
    testDigitStrippingPSA_EmptyString();
    testDigitStrippingPSA_OnlyDigits();
    testDigitStrippingPSA_NoDigits();
    testDigitStrippingPSA_MixedDigits();
}

int main()
{
    testUppercasingPSA();
    testDigitStrippingPSA();

    return 0;
}
