//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/21/24
// JoseMedranoHW2.cpp
// Win10
// Visual Studio 2022
//
// 
//

#include <iostream>
using namespace std;

/******************************************************************************
* Queue class definitions
******************************************************************************/
const int INCREASE_MULTIPLIER = 2;

template <typename T>
class Queue
{
public:
    Queue(); // Construct empty queue
    ~Queue(); // Destructor
    Queue(const Queue&); // Copy constructor
    //Queue& operator=(const Queue&); // Copy assignment operator
    void push(const T&); // Add elem to back of queue
    //void pop(); // Remove front elem from queue
    T& front(); // Return ref to front elem in queue
    //const T& front() const; // Return ref to front elem in queue
    bool empty() const; // Return whether queue is empty
    size_t size() const; // Return # of elems in queue
private:
    T *v_; // Elems in queue
    T* newCopy(const T* src, size_t srcsize, size_t destsize);

    /* Any other private members you need */
    size_t vsize;
    size_t vused;

};

template < typename T>
T*
Queue<T>::newCopy(const T * src, size_t srcsize, size_t destsize)
{
    T *dest = new T[destsize];
    try
    {
        copy(src, src + srcsize, dest);
    }
    catch (...)
    {
        delete[] dest; // This can't throw
        throw; // Rethrow original exception
    }
    return dest;
}

template <typename T>
Queue<T>::Queue() : v_(0), vsize(0), vused(0)
{
    v_ = new T[vsize];
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] v_;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& other) :
    v_(newCopy(other.v_, other.vsize, other.vsize)),
    vsize(other.vsize),
    vused(other.vused)
{
    
}

template <typename T>
void
Queue<T>::push(const T& t)
{
    if (vused == vsize) {
        size_t vsize_new = vsize * INCREASE_MULTIPLIER;
        T* v_new = newCopy(v_, vsize, vsize_new);
        delete[] v_;
        v_ = v_new;
        vsize = vsize_new;
    }
    v_[vused] = t;
    vused++;
}

template <typename T>
T &
Queue<T>::front() 
{
    if (vused == 0) {
        throw logic_error("Front from empty queue");
    }
    return v_[0];
}

template <typename T>
bool
Queue<T>::empty() const
{
    if (vused == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
size_t
Queue<T>::size() const
{
    return vsize;
}

/******************************************************************************
* Unit tests
******************************************************************************/
void
testConstructor() 
{
    Queue<int> test;
    if (test.empty() && test.size() == 0) {
        clog << "testConstructor PASSED\n";
    }
    else {
        clog << "testConstructor FAILED: vsize and vused should be 0 and v_ " <<
            "should be empty\n";
    }
}

void
testDestructor()
{

}

void 
testCopyConstructor()
{
    Queue<int> sample;
    sample.push(1);

    Queue<int> copy_sample(sample);

    if (sample.front() == copy_sample.front()) {
        clog << "testCopyConstructor PASSED\n";
    }
    else {
        clog << "testCopyConstructor FAILED: Original Queue has a front with "
            "value " << sample.front() << " and the copy Queue has a front with"
            " " << copy_sample.front() << "\n";
    }
}

void
testCopyAsssignment()
{

}

void
testAllFunctions() 
{
    testConstructor();
    //testDestructor();
    testCopyConstructor();
}
/******************************************************************************
* main function for unit tests
******************************************************************************/

int main() 
{
    Queue<int> test1;
    Queue<int> test2;

    test1.push(1);
    test2.push(6);
    //testAllFunctions();
    return 0;
}
