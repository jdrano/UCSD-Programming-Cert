//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 177752, Prof. Mitchell
// 02/18/24
// HW6_Main.cpp
// Win10
// Visual Studio 2022
//
// Contains test for edge cases on our palindrome check and compress function
//

#include <list>
#include <iostream>
using namespace std;

#include "Algorithms.h"
int main()
{
    /***************************************************************************
    *  Testing Palindrome Function
    ***************************************************************************/
    cout << "Testing Palindrome edge cases\n";

    // Test empty list
    {
        list<int> ls1;
        if (palindrome(ls1.begin(), ls1.end()) == true)
        {
            cout << "Test an empty list PASSED\n";
        }
        else
        {
            cout << "Test an empty list FAILED\n";
            exit(EXIT_FAILURE);
        }
    }
    
    // Test a list that has an odd number of elements that form a palindrome
    {
        int data[] = { 1, 2, 1 };
        list<int> ls2(data, data + 3);
        if (palindrome(ls2.begin(), ls2.end()) == true)
        {
            cout << "Test a list containing an odd number of elements that "
                << "form a palindrome PASSED\n";
        }
        else
        {
            cout << "Test a list containing an odd number of elements that "
                << "form a palindrome FAILED\n";
            exit(EXIT_FAILURE);
        }
    }

    // Test list that has an even number of elements that form a palindrome
    {
        int data[] = { 2, 1, 1, 2 };
        list<int> ls3(data, data + 4);
        if (palindrome(ls3.begin(), ls3.end()) == true)
        {
            cout << "Test a list containing an even number of elements that "
                << "form a palindrome PASSED\n";
        }
        else
        {
            cout << "Test a list containing an even number of elements that "
                << "form a palindrome FAILED\n";
            exit(EXIT_FAILURE);
        }
    }

    // Test list that has an odd number of elements that form a non-palindrome
    {
        int data[] = { 1, 2, 3 };
        list<int> ls4(data, data + 3);
        if (palindrome(ls4.begin(), ls4.end()) == false)
        {
            cout << "Test a list containing an odd number of elements that "
                << "form a non-palindrome PASSED\n";
        }
        else
        {
            cout << "Test a list containing an odd number of elements that "
                << "form a non-palindrome FAILED\n";
            exit(EXIT_FAILURE);
        }
    }

    // Test list that has an even number of elements that form a non-palindrome
    {
        int data[] = { 1, 2, 3, 4 };
        list<int> ls4(data, data + 4);
        if (palindrome(ls4.begin(), ls4.end()) == false)
        {
            cout << "Test a list containing an even number of elements that "
                << "form a non-palindrome PASSED\n";
        }
        else
        {
            cout << "Test a list containing an even number of elements that "
                << "form a non-palindrome FAILED\n";
            exit(EXIT_FAILURE);
        }
    }

    /***************************************************************************
    *  Testing Compress Function
    ***************************************************************************/
    cout << "\nTesting Compress edge cases\n";

    // Test empty list
    {
        list<int> ls1, ls2;
        compress(ls1.begin(), ls1.end(), back_inserter(ls2));
        if (ls2.empty()) {
            cout << "Test an empty list PASSED\n";
        }
        else {
            cout << "Test an empty list FAILED!\n";
        }
    }

    // Test list that has no consecutive duplicates
    {
        int data[] = { 1, 2, 3, 1, 2, 3 };
        list<int> ls3(data, data + 6), ls4;
        compress(ls3.begin(), ls3.end(), back_inserter(ls4)); 
        if (ls3 == ls4)
        {
            cout << "Test list that has no consecutive duplicates PASSED\n";
        }
        else
        {
            cout << "Test list that has no consecutive duplicates FAILED\n";
        }
    }

    // Test list containing duplicates
    {
        int data[] = { 1, 1, 2, 2, 1, 1 };
        int cmp[] = { 1, 2, 1 };
        list<int> ls5(data, data + 6), ls6, ls7(cmp, cmp + 3);
        compress(ls5.begin(), ls5.end(), back_inserter(ls6)); 
        if (ls6 == ls7)
        {
            cout << "Test list that has duplicates PASSED\n";
        }
        else
        {
            cout << "Test list that has duplicates FAILED\n";
        }
    }
}