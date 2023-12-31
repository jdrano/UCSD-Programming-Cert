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
        PeriodicSignal(double voltageOffset, Time TimeOffset, 
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
        virtual double getVoltageAtTime(Time t) const = 0;

    protected:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns the min voltage.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      A double referring to the minimum volts of the periodic signal.
        //---------------------------------------------------------------------
        double getMinVoltage() const;

        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns the max voltage.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      A double referring to the maximum volts of the periodic signal.
        //---------------------------------------------------------------------
        double getMaxVoltage() const;

        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns the time of the period.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      A time object that references to the length of the period.
        //---------------------------------------------------------------------
        Time getPeriod() const;

    private:
        double minVoltage;
        double maxVoltage;
        Time period;
    };
}

#endif