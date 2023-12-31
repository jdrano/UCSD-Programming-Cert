// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// Sensor.cpp
// Win10
// Visual Studio 2022
// Declarations for Sensor class.

#include "Sensor.h"

using namespace std;
using namespace Project2;


// Constructors
Project2::Sensor::Sensor(string name, Signal &source) :
    name(name), source(source)
{

}

// Getters
string
Project2::Sensor::getName() const {
    return name;
}

Signal&
Project2::Sensor::getSource() const {
    return source;
}

void
Project2::Sensor::takeReading(Time t, DataRecorder &recorder) {
    recorder.log(t, getName(), getSource().getVoltageAtTime(t), getUnits());
}