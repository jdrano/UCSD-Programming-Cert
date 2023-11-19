// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// Sensor.h
// Win10
// Visual Studio 2022
// Definitions for Sensor abstract class.

#ifndef PROJECT2_SENSOR_H
#define PROJECT2_SENSOR_H

#include "Time.h"
#include "Signal.h"
#include "DataRecorder.h"

namespace Project2
{
    //=========================================================================
    // SUMMARY
    //      The Sensor class is an abstract class, a layout, for various 
    //      derived sensor classes.
    //       
    // RESOURCES
    //      None
    //=========================================================================
    class Sensor
    {
    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a Sensor object
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      name
        //          The name of the sensor
        //      &source
        //          Reference to the source of the signal
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        Sensor(string name, Signal &source);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Logs information into the recorder at the given Time t.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      t
        //          Time object we will be using to record the log
        //      recorder
        //          DataRecorder object that holds the ostream of the log
        //
        // RETURNS
        //      None
        //---------------------------------------------------------------------
        void takeReading(Time t, DataRecorder &recorder);

    protected:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns a string of the unit based on the type of sensor
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      String detailing unit type
        //---------------------------------------------------------------------
        virtual string getUnits() const = 0;

        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns a string of the name of the sensor.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      String detailing the name.
        //---------------------------------------------------------------------
        string getName() const;

        //---------------------------------------------------------------------
        // SUMMARY
        //      Returns the signal tied with the sensor.
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      The Signal of the sensor.
        //---------------------------------------------------------------------
        Signal& getSource() const;

    private:
        string name;
        Signal &source;
    };
}

#endif