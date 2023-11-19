// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// DataRecorder.h
// Win10
// Visual Studio 2022
// Definitions for DataRecorder class.

#ifndef PROJECT2_DATARECORDER_H
#define PROJECT2_DATARECORDER_H

#include "Time.h"

namespace Project2
{
    //=========================================================================
    // SUMMARY
    //      The DataRecorder object contains an output stream of the log
    //      information.
    //       
    // RESOURCES
    //      None
    //=========================================================================
    class DataRecorder
    {
    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a DataRecorder object
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      &out
        //          reference to an output stream belonging to the data recorder
        //          object
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        DataRecorder(ostream &out);

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
        string log(Time Timestamp, string sensorName, double sensorVoltage, 
            string sensorUnits);

        
    private:
        ostream &out;
    };
}

#endif