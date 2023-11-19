// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// MonitoringSystem.h
// Win10
// Visual Studio 2022
// Definitions for MonitoringSystem class.

#ifndef PROJECT2_MONITORINGSYSTEM_H
#define PROJECT2_MONITORINGSYSTEM_H

#include <iostream>
#include "Time.h"
#include "Sensor.h"
#include "AngularSensor.h"
#include "PressureSensor.h"
#include "TemperatureSensor.h"
#include "VibrationSensor.h"
#include <vector>
#include "DataRecorder.h"

namespace Project2
{
    //=========================================================================
    // SUMMARY
    //      The MonitoringSystem object contains hours, minutes, and seconds,
    //       
    // RESOURCES
    //      None
    //=========================================================================
    class MonitoringSystem
    {
    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a MonitoringSystem object
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      &out
        //          
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        MonitoringSystem(ostream &out);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Adds the passed sensor to the system's array of sensors
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      *s
        //          Pointer to a sensor that is to be added to the array 
        //          of sensors.
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        void addSensor(Sensor *s);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Reads out the given time.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      t
        //          Time object to be read.
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        void takeReading(Time t);

    private:
        ostream &out;
        DataRecorder recorder;
        vector<Sensor*> ordered;
    };

}

#endif