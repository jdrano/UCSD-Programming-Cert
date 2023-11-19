// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// TemperatureSensor.h
// Win10
// Visual Studio 2022
// Definitions for TemperatureSensor class.

#ifndef PROJECT2_TEMPERATURESENSOR_H
#define PROJECT2_TEMPERATURESENSOR_H

#include "Time.h"

namespace Project2
{
    //=========================================================================
    // SUMMARY
    //      The TemperatureSensor class is an derived sensor class that focuses on
    //      
    //       
    // RESOURCES
    //      None
    //=========================================================================
    class Sensor
    {
    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a TemperatureSensor object
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      name
        //          The name of the TemperatureSensor
        //      &source
        //          Reference to the source of the signal
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        TemperatureSensor(string name, Signal &source);

    protected:
        string getUnits() const;

    };
}

#endif