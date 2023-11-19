// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// ConstantSignal.cpp
// Win10
// Visual Studio 2022
// Declarations for ConstantSignal class.

#include "ConstantSignal.h"

using namespace std;
using namespace Project2;

// Constructors
Project2::ConstantSignal::ConstantSignal(double voltageOffset, Time TimeOffset)
    :Signal(voltageOffset, TimeOffset)
{

}

// Getters
double
Project2::ConstantSignal::getVoltageAtTime(Time t) const {
    return getVoltageOffset();
}