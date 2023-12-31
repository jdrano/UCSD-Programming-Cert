// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// Signal.h
// Win10
// Visual Studio 2022
// Definitions for Signal abstract class.

#ifndef PROJECT2_SIGNAL_H
#define PROJECT2_SIGNAL_H

#include "Time.h"

namespace Project2
{
    //=========================================================================
    // SUMMARY
    //      The Signal class is an abstract class, a layout, for constant signal
    //      and the periodic signal, and their derived classes.
    //       
    // RESOURCES
    //      None
    //=========================================================================
    class Signal
    {
    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a Signal object
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      voltageOffset
        //          The voltage offset based off the signal
        //      TimeOffset
        //          A Time object that tracks the variation of Time.
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        Signal(double voltageOffset, Time TimeOffset);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns a string of information containing the Time and the data
        //      associated with the sensors and voltage at that Time.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      Timestamp
        //          Our Time object associated with the snapshot
        //      sensorName
        //          The name of the sensor of our snapshot
        //      sensorVoltage
        //          The volts given off from our sensor
        //      sensorUnits
        //          The measurement of what type of units we are measuring
        //
        // RETURNS
        //      A string detailing all info on a sensor at a given Time.
        //---------------------------------------------------------------------
        virtual double getVoltageAtTime(Time t) const = 0;

    protected:
        Time getTimeOffset() const;
        double getVoltageOffset() const;

    private:
        Time TimeOffset;
        double voltageOffset;
    };
}

#endif