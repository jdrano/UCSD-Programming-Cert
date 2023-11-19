// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// MonitoringSystem.cpp
// Win10
// Visual Studio 2022
// Declarations for MonitoringSystem class.

#include "MonitoringSystem.h"

using namespace Project2;


// Constructors
Project2::MonitoringSystem::MonitoringSystem(ostream &out) :
    out(out), recorder(out)
{

}

// Getters
void
Project2::MonitoringSystem::addSensor(Sensor *s) {
    ordered.push_back(s);
}

void
Project2::MonitoringSystem::takeReading(Time t) {
    for (int curr_sensor = 0; curr_sensor < ordered.size(); curr_sensor++) {
        ordered.at(curr_sensor)->takeReading(t, recorder);
    }

}