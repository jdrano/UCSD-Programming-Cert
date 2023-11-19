// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// AngularSensor.cpp
// Win10
// Visual Studio 2022
// Declarations for AngularSensor class.

#include "AngularSensor.h"

using namespace std;
using namespace Project2;


// Constructors
Project2::AngularSensor::AngularSensor(string name, Signal &source) : 
    source(source)
{
    strcpy(this->name, name);
}

// Getters
String
Project2::AngularSensor::getUnits() const {
    return "Radians";
}
