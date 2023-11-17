// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// PeriodicSignal.h
// Win10
// Visual Studio 2022
// Definitions for PeriodicSignal class.

#ifndef PROJECT2_PERIODICSIGNAL_H
#define PROJECT2_PERIODICSIGNAL_H

#include "Signal.h"

namespace Project2
{
    //=========================================================================
    // SUMMARY
    //      The PeriodicSignal class is an abstract class, a layout, for 
    //      Periodic Signal and the periodic signal, and their derived classes.
    //       
    // RESOURCES
    //      None
    //=========================================================================
    class PeriodicSignal : public Signal
    {
    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a PeriodicSignal object
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      voltageOffset
        //          The voltage offset based off the signal
        //      timeOffset
        //          A time object that tracks the variation of time.
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
        PeriodicSignal(double voltageOffset, Time timeOffset, 
            double minVoltage, double maxVoltage, Time period);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns the voltage at a given time.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      t
        //          The time object we will access to aquire the voltage
        //
        // RETURNS
        //      A double referring to the amount of volts in a given time
        //---------------------------------------------------------------------
        virtual double getVoltageAtTime(Time t) const = 0;

    protected:
        double getMinVoltage() const;
        double getMaxVoltage() const;
        Time getPeriod() const;

    private:
        double minVoltage;
        double maxVoltage;
        Time period;
    };
}

#endif