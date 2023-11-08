// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 4/14/23
// C1A1E1_main.cpp
// Win10
// Visual Studio 2022
// 
// Describes the correct syntax for a list of expressions.

#include <iostream>
using namespace std;

int main() {
    cout << "\"ax = ax + bx\" should be \"ax += bx\"\n"
        "\"ax = ax / -bx\" should be \"ax /= -bx\"\n"
        "\"ax = bx / ax\" should be \"ax = bx / ax\"\n"
        "\"ax = -1 * ax\" should be \"ax = -ax\"\n"
        "\"ax = -ax * ax\" should be \"ax *= -ax\"\n"
        "\"ax = -bx * ax\" should be \"ax *= -bx\"\n"
        "\"ax = bx - ax\" should be \"ax = bx - ax\"\n"
        "\"ax = 2 + ax\" should be \"ax += 2\"\n"
        "\"ax = 1 + ax\" should be \"++ax\" or \"ax++\"\n"
        "\"ax = ax - 37\" should be \"ax -= 37\"\n"
        "\"ax = ax - 1\" should be \"--ax\" or \"ax--\"\n"
        "\"ax *= -1\" should be \"ax = -ax\"\n"
        "\"ax /= -1\" should be \"ax = -ax\"\n"
        "\"ax = 0 - ax\" should be \"ax = -ax\"\n";
    return 0;
}
