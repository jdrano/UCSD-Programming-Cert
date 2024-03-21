class Test {
public:
    static int count;
    Test(int value = 0) : value(value) { ++count; }
    ~Test() { --count; }

    int value;
};
int Test::count = 0;

class DerivedTest : public Test {};