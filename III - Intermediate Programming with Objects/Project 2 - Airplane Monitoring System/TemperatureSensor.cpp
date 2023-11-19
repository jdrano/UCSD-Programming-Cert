// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// TemperatureSensor.cpp
// Win10
// Visual Studio 2022
// Declarations for TemperatureSensor class.

#include "TemperatureSensor.h"

using namespace std;
using namespace Project2;


// Constructors
Project2::TemperatureSensor::TemperatureSensor(string name, Signal &source) :
    Sensor(name, source)
{

}

// Getters
string
Project2::TemperatureSensor::getUnits() const {
    return "Degrees Celsius";
}