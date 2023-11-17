// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// SawtoothSignal.cpp
// Win10
// Visual Studio 2022
// Declarations for SawtoothSignal class.

#include "SawtoothSignal.h"

using namespace std;
using namespace Project2;

// Constructors
Project2::SawtoothSignal::SawtoothSignal(double voltageOffset, Time timeOffset,
    double minVoltage, double maxVoltage, Time period)
    : PeriodicSignal(voltageOffset, timeOffset, minVoltage, maxVoltage, period)
{

}

// Getters
double
Project2::SawtoothSignal::getVoltageAtTime(Time t) const {
    double section1 = getVoltageOffset() + getMinVoltage();

    double section2 = t.getTotalTimeAsSeconds() +
        getTimeOffset().getTotalTimeAsSeconds();

    double section3 = getMaxVoltage() - getMinVoltage();

    double section4 = (section2 * section3) / 
        getPeriod().getTotalTimeAsSeconds();

    double finalValue = section1 + fmod(section4, section3);

    return finalValue;
}