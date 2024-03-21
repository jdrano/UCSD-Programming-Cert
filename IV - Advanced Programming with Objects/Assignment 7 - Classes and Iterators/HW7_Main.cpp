//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/24/24
// HW7_Main.cpp
// Win10
// Visual Studio 2022
//
// File contains class definition for IntegerRange class and an iterator class
// within. Contains main function with tests that ensure the iterator works as
// designed.
//

#include <iostream>     // std::cout
#include <iterator>     // std::ostream_iterator
#include <algorithm>    // std::copy
#include <numeric>      // std::accumuulate
#include <cassert>
using namespace std;

// Represents all integer values in the range [low, high).
// low must be <= high.
template <typename T>
class IntegerRange
{
public:

    // Class definition for the iterator. It is an forward input iterator 
    class iterator
    {
    public:
        using difference_type = T;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::forward_iterator_tag;

        iterator(T it) : it_(it) {}
        T operator*() const
        {
            return it_;
        }

        bool operator==(const iterator& other) const
        {
            return it_ == other.it_;
        }

        bool operator!=(const iterator& other) const
        {
            return it_ != other.it_;
        }

        iterator& operator++()
        {
            it_++;
            return *this;
        }

    private:
        T it_;
    };

    IntegerRange(T low, T high) : low_(low), high_(high)
    {
        assert(low <= high);
    }

    const iterator begin() const 
    { 
        return iterator(low_); 
    }
    const iterator end() const 
    { 
        return iterator(high_); 
    }

private:
    const T low_, high_;
};

int main()
{
    /***************************************************************************
    * 
    * Implement 4 tests demonstrating IntegerRange<T> working with 4 integer 
    * types(e.g. int, long) and 4 algorithms of your choice. Note, each test is 
    * only required to test one integer type and one algorithm.
    * 
    ***************************************************************************/

    // Test 1
    IntegerRange<int> const r1(-2, 3);
    copy(r1.begin(), r1.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    // Test 2
    IntegerRange<double> r2(-8.0, 10.0);
    double sum = accumulate(r2.begin(), r2.end(), 0);
    cout << "Sum: " << sum << '\n';

    // Test 3
    IntegerRange<float> r3(1.0F, 9.0F);
    auto result = find(r3.begin(), r3.end(), 2);
    if (result != r3.end()) {
        cout << "Found: " << *result << '\n'; // Outputs: Found: 2
    }
    else {
        cout << "Not found" << '\n';
    }

    // Test 4
    IntegerRange<long> r4(-50000, 20000);
    int myCount = count(r4.begin(), r4.end(), 0);
    cout << "0 appears " << myCount << " times.\n";

    return 0;
}