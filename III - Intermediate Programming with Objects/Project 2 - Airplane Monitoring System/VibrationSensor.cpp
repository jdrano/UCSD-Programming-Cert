// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// VibrationSensor.cpp
// Win10
// Visual Studio 2022
// Declarations for VibrationSensor class.

#include "VibrationSensor.h"

using namespace std;
using namespace Project2;


// Constructors
Project2::VibrationSensor::VibrationSensor(string name, Signal &source) :
    Sensor(name, source)
{
    
}

// Getters
string
Project2::VibrationSensor::getUnits() const {
    return "Hertz (Hz)";
}