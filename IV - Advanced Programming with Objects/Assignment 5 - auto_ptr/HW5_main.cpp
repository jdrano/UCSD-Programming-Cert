//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 177752, Prof. Mitchell
// 02/13/24
// HW5_main
// Win10
// Visual Studio 2022
//
// Main to test our auto_ptr class.
//

#include <cassert>
using namespace std;

#include "auto_ptr.h"
#include "test_class.h"

int main()
{
    // Test constructr
    {
        auto_ptr<Test> p(new Test);
        assert(Test::count = 1);
    }
    assert(Test::count == 0);

    // Test copy constructor
    {
        auto_ptr<Test> p1(new Test);
        auto_ptr<Test> p2(p1);
        assert(Test::count == 1);
        assert(p1.get() == 0);
        assert(p2.get() != 0);
    }
    assert(Test::count == 0);

    // Test template copy constructor
    {
        auto_ptr<DerivedTest> p1(new DerivedTest);
        auto_ptr<Test> p2(p1);
        assert(Test::count == 1);
        assert(p1.get() == 0);
        assert(p2.get() != 0);
    }
    assert(Test::count == 0);

    // Test destructor
    {
        auto_ptr<Test> p(new Test);
        assert(Test::count = 1);
    }
    assert(Test::count == 0);

    // Test getter
    {
        auto_ptr<Test> p(new Test);
        assert(p.get() != 0);
        p.release();
        assert(p.get() == 0);
    }

    // Test dereference and arrow accessors
    {
        auto_ptr<Test> p(new Test(10));
        assert((*p).value == 10);
        assert(p->value == 10);
        p.release();
    }

    // Unit test for release function
    {
        Test::count = 0;
        auto_ptr<Test> p(new Test);
        assert(Test::count == 1);
        Test* raw_ptr = p.release();
        assert(Test::count == 1);
        assert(p.get() == 0);
        delete raw_ptr;
        assert(Test::count == 0);
    }

    // Unit test for reset function
    {
        auto_ptr<Test> p(new Test);
        assert(Test::count == 1);
        p.reset(new Test);
        assert(Test::count == 1);
    }

    
}