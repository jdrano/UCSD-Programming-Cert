//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 177752, Prof. Mitchell
// 02/18/24
// Algorithms.cpp
// Win10
// Visual Studio 2022
//
// 
//

#include "Algorithms.h"
#include <iterator>
using namespace std;

template <typename BidirectionalIterator>
bool palindrome(BidirectionalIterator first, BidirectionalIterator last)
{
    for (auto reverse_it = make_reverse_iterator(last); 
        first != last; first++, reverse_it++)
    {
        if (*first != *reverse_it)
        {
            return false;
        }
    }
    return true;
}

template <typename ForwardIterator, typename OutputIterator>
void compress(ForwardIterator first, ForwardIterator last,
    OutputIterator result)
{
    if (first == last)
    {
        return true;
    }

    ForwardIterator prev = first;
    *result = *first;
    result++;

    for (first++; first != last; first++)
    {
        if (*first != *prev)
        {
            result = *first;
            ++result;
            prev = first;
        }
    }
}