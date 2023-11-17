// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// PeriodicSignal.cpp
// Win10
// Visual Studio 2022
// Declarations for PeriodicSignal class.

#include "PeriodicSignal.h"

using namespace std;
using namespace Project2;

// Constructors
Project2::PeriodicSignal::PeriodicSignal(double voltageOffset, Time timeOffset,
    double minVoltage, double maxVoltage, Time period)
    : Signal(voltageOffset, timeOffset), minVoltage(minVoltage), 
    maxVoltage(maxVoltage), period(period)
{

}

// Getters
double
Project2::PeriodicSignal::getVoltageAtTime(Time t) const {
    return getVoltageOffset();
}

double
Project2::PeriodicSignal::getMinVoltage() const {
    return minVoltage;
}

double
Project2::PeriodicSignal::getMaxVoltage() const {
    return maxVoltage;
}

Time
Project2::PeriodicSignal::getPeriod() const {
    return period;
}