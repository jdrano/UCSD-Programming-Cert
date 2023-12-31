// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// SineSignal.h
// Win10
// Visual Studio 2022
// Definitions for SineSignal class.

#ifndef PROJECT2_SINESIGNAL_H
#define PROJECT2_SINESIGNAL_H

#include "PeriodicSignal.h"

namespace Project2
{
    //=========================================================================
    // SUMMARY
    //      The SineSignal class is an abstract class, a layout, for constant 
    //      signal and the periodic signal, and their derived classes.
    //       
    // RESOURCES
    //      None
    //=========================================================================
    class SineSignal : public PeriodicSignal
    {
    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a SineSignal object
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      voltageOffset
        //          The voltage offset based off the signal
        //      TimeOffset
        //          A Time object that tracks the variation of Time.
        //      minVoltage
        //          The lowest voltage the signal ranges from
        //      maxVoltage
        //          The highest voltage the signal ranges from
        //      period
        //          Time object to define the period of the signal
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        SineSignal(double voltageOffset, Time TimeOffset,
            double minVoltage, double maxVoltage, Time period);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns the voltage at a given Time.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      t
        //          The Time object we will access to aquire the voltage
        //
        // RETURNS
        //      A double referring to the amount of volts in a given Time
        //---------------------------------------------------------------------
        double getVoltageAtTime(Time t) const;
    };
}

#endif