//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 177752, Prof. Mitchell
// 02/18/24
// Algorithms.h
// Win10
// Visual Studio 2022
//
// Contains the template functions that check iterators to see if they are
// a palindrome or they compress them shorter arrays.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iterator>

template <typename BidirectionalIterator>
bool palindrome(BidirectionalIterator first, BidirectionalIterator last)
{
    // Check first and last iterator, if equal move closer
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
        return;
    }

    ForwardIterator prev = first;
    *result = *first;
    result++;

    // Check every value in the first iterator until we reach the end
    for (first++; first != last; first++)
    {
        // If the next value is not the current iterator value, move on
        if (*first != *prev)
        {
            result = *first;
            ++result;
            prev = first;
        }
    }
}

#endif