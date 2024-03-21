//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 177752, Prof. Mitchell
// 01/14/24
// JoseMedranoHW1.cpp
// Win10
// Visual Studio 2022
//
// The file creates unit tests on some STL functions.
//

#include <deque>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


/******************************************************************************
* Functions relevant to answering Question 1 on Assignment 1
******************************************************************************/

// Defining the generator function for DequeTest
int gen()
{
    static int i = 0;
    return ++i;
}

//-----------------------------------------------------------------------------
// SUMMARY
//      Tests that the Accumulate function is successfully equated to 55, which 
//      is the correct value when adding all the values of our generateDeque 
//      test.
//
// RESOURCES
//      None
//
// PARAMETERS
//      None
//      
// RETURNS
//      Nothing
//-----------------------------------------------------------------------------
void
testDequeAccumulate() {
    const int TRUE_SUM = 55;

    // Setup the deque to be filled with values 1 - 10
    deque<int> testDeque;
    generate_n(back_inserter(testDeque), 10, gen);
    int sum = accumulate(testDeque.cbegin(), testDeque.cend(), 0);

    // Check that sum of deque equates to 55
    if (sum != TRUE_SUM) {
        clog << "testDequeAccumulate FAILED: Expected sum " << 55
            << " instead saw balance " << sum;
    }
    else {
        clog << "testDequeAccumulate PASSED";
    }
    clog << '\n';
}

/******************************************************************************
* Functions relevant to answering Question 2 on Assignment 1
******************************************************************************/

//-----------------------------------------------------------------------------
// SUMMARY
//      Tests that the string is successfully transformed into an upper-cased
//      version of itself using the STL function "transform()".
// 
// RESOURCES
//      None
//
// PARAMETERS
//      None
//      
// RETURNS
//      Nothing
//-----------------------------------------------------------------------------
void
testStringTransform() {
    const string UPPER_ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Create a string of the alphabet and apply the STL transform function
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    transform(alphabet.begin(), alphabet.end(), alphabet.begin(), toupper);

    // Check for matching strings
    if (alphabet.compare(UPPER_ALPHABET) == 0) {
        clog << "testStringTransform PASSED";
    }
    else {
        clog << "testStringTransform FAILED: Expected string " << UPPER_ALPHABET
            << " instead saw string " << alphabet;
    }

    clog << '\n';
}

/******************************************************************************
* Functions relevant to answering Question 3 on Assignment 1
******************************************************************************/

//-----------------------------------------------------------------------------
// SUMMARY
//      Tests that the partition, sort, and copy STL functions properly do as 
//      they are described to.
// 
// RESOURCES
//      None
//
// PARAMETERS
//      None
//      
// RETURNS
//      Nothing
//-----------------------------------------------------------------------------
void
testVectorAlgorithm() {
    int values[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // Create a vector using vector iterator range constructor
    vector<int> vecValues(values, values + sizeof(values) / sizeof(values[0]));
    
    // Changes 1st half of vector to be even, and 2nd half to odd
    partition(vecValues.begin(), vecValues.end(), [](int i) 
        {return i % 2 == 0; });

    // Orders lower half in ascending order
    sort(vecValues.begin(), vecValues.begin() + (vecValues.size() / 2 ));

    // Orders upper half in ascending order
    sort(vecValues.begin() + (vecValues.size() / 2), vecValues.end());

    // Copy the vector into an ostringstream
    ostringstream output;
    copy(vecValues.begin(), vecValues.end(), ostream_iterator<int>(output));

    // Compare if partition, sort, and copy function properly worked
    ostringstream answer;
    answer.str("24681013579");
    if (output.str() == answer.str()) {
        clog << "testVectorAlgorithm PASSED";
    }
    else {
        clog << "testVectorAlgorithm FAILED: Expected ostringstream " <<
            answer.str() << " instead saw ostringstream " << output.str();
    }
}

int main() {

    // Question 1
    testDequeAccumulate();

    // Question 2
    testStringTransform();

    // Question 3
    testVectorAlgorithm();

    return 0;
}