// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// VibrationSensor.h
// Win10
// Visual Studio 2022
// Definitions for TemperatureSensor class.

#ifndef PROJECT2_VIBRATIONSENSOR_H
#define PROJECT2_VIBRATIONSENSOR_H

#include "Time.h"

namespace Project2
{
    //=========================================================================
    // SUMMARY
    //      The VibrationSensor class is an derived sensor class that focuses on
    //      
    //       
    // RESOURCES
    //      None
    //=========================================================================
    class VibrationSensor
    {
    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a VibrationSensor object
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      name
        //          The name of the VibrationSensor
        //      &source
        //          Reference to the source of the signal
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        VibrationSensor(string name, Signal &source);

    protected:
        string getUnits() const;

    };
}

#endif