// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// PressureSensor.h
// Win10
// Visual Studio 2022
// Definitions for PressureSensor class.

#ifndef PROJECT2_PRESSURESENSOR_H
#define PROJECT2_PRESSURESENSOR_H

#include "Time.h"
#include "Sensor.h"

namespace Project2
{
    //=========================================================================
    // SUMMARY
    //      The PressureSensor class is an derived sensor class that focuses on
    //      
    //       
    // RESOURCES
    //      None
    //=========================================================================
    class PressureSensor : public Sensor
    {
    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a PressureSensor object
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      name
        //          The name of the PressureSensor
        //      &source
        //          Reference to the source of the signal
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        PressureSensor(string name, Signal &source);

    protected:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns the type of units necessary per type of sensor
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      A string of the name of the unit type
        //---------------------------------------------------------------------
        string getUnits() const;

    };
}

#endif