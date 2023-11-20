// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// AngularSensor.h
// Win10
// Visual Studio 2022
// Definitions for AngularSensor class.

#ifndef PROJECT2_ANGULARSENSOR_H
#define PROJECT2_ANGULARSENSOR_H

#include "Sensor.h"
namespace Project2
{
    //=========================================================================
    // SUMMARY
    //      The AngularSensor class is an derived sensor class that focuses on
    //      measurements in radians.      
    //       
    // RESOURCES
    //      None
    //=========================================================================
    class AngularSensor : public Sensor
    {
    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a AngularSensor object
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      name
        //          The name of the AngularSensor
        //      &source
        //          Reference to the source of the signal
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        AngularSensor(string name, Signal &source);

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