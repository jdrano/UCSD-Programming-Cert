// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// PressureSensor.cpp
// Win10
// Visual Studio 2022
// Declarations for PressureSensor class.

#include "PressureSensor.h"

using namespace std;
using namespace Project2;


// Constructors
Project2::PressureSensor::PressureSensor(string name, Signal &source) : 
    source(source)
{
    strcpy(this->name, name);
}

// Getters
String
Project2::PressureSensor::getUnits() const {
    return "Pounds per square inch (PSI)";
}
