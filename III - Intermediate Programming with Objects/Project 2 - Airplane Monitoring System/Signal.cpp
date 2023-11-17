// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// Signal.cpp
// Win10
// Visual Studio 2022
// Declarations for Signal class.

#include "Signal.h"

using namespace std;
using namespace Project2;


// Constructors
Project2::Signal::Signal(double voltageOffset, Time timeOffset) : 
    voltageOffset(voltageOffset), timeOffset(timeOffset)
{

}

// Getters
Time
Project2::Signal::getTimeOffset() const {
    return timeOffset;
}

double
Project2::Signal::getVoltageOffset() const {
    return voltageOffset;
}