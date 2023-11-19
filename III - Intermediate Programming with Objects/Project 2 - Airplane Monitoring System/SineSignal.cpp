// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// SineSignal.cpp
// Win10
// Visual Studio 2022
// Declarations for SineSignal class.

#include "SineSignal.h"
#include <cmath>

using namespace std;
using namespace Project2;

// Constructors
Project2::SineSignal::SineSignal(double voltageOffset, Time TimeOffset,
    double minVoltage, double maxVoltage, Time period)
    : PeriodicSignal(voltageOffset, TimeOffset, minVoltage, maxVoltage, period)
{

}

// Getters
double
Project2::SineSignal::getVoltageAtTime(Time t) const {
    double PI = 3.14159265358979323846;

    double section1 = getVoltageOffset() + getMinVoltage() +
        ((getMaxVoltage() - getMinVoltage()) / 2);
    
    double section2 = sin(((t.getTotalTimeAsSeconds() + 
        getTimeOffset().getTotalTimeAsSeconds()) * 2 * PI) / 
        getPeriod().getTotalTimeAsSeconds());

    double section3 = (section2 * (getMaxVoltage() - getMinVoltage())) / 2;

    double finalValue = section1 + section3;
    return finalValue;
}