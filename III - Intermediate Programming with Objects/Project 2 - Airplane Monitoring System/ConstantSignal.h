// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// ConstantSignal.h
// Win10
// Visual Studio 2022
// Definitions for ConstantSignal class.

#ifndef PROJECT2_CONSTANTSIGNAL_H
#define PROJECT2_CONSTANTSIGNAL_H

#include "Signal.h"

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
    class ConstantSignal : public Signal
    {
    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a ConstantSignal object
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
        ConstantSignal(double voltageOffset, Time TimeOffset);

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