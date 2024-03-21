//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 177752, Prof. Mitchell
// 02/13/24
// auto_ptr.h
// Win10
// Visual Studio 2022
//
// Header file for the template class auto_ptr
//

#ifndef AUTO_PTR_H
#define AUTO_PTR_H

template <typename X>
class auto_ptr
{
private:
    X* ptr;

public:
    // Constructors
    explicit auto_ptr(X *p = 0) throw() : ptr(p)
    {

    }

    auto_ptr(auto_ptr &p) throw() : ptr(p.release())
    {

    }

    template <typename Y> auto_ptr(auto_ptr<Y> &p) throw() : ptr(p.release())
    {

    }

    // Destructor
    ~auto_ptr() throw()
    {
        delete ptr;
    }

    // Access
    X *get() const throw()
    {
        return ptr;
    }

    X &operator*() const throw()
    {
        return *ptr;
    }

    X *operator->() const throw()
    {
        return ptr;
    }

    // Assignment
    auto_ptr &operator=(auto_ptr &p) throw()
    {
        if (this != p)
        {
            reset(p.release());
        }
        return *this;
    }

    template <typename Y> auto_ptr &operator=(auto_ptr<Y> &p) throw()
    {
        reset(p.release());
        return *this;
    }

    // Release & Reset
    X *release() throw()
    {
        X* tmp = ptr;
        ptr = 0;
        return tmp;
    }

    void reset(X *p = 0) throw()
    {
        if (ptr != p)
        {
            delete ptr;
            ptr = p;
        }
    }
};

#endif