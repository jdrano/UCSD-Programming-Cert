// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// Time.h
// Win10
// Visual Studio 2022
// Definitions for Time class.

#ifndef PROJECT2_TIME_H
#define PROJECT2_TIME_H

#include <iostream>
using namespace std;

namespace Project2
{
    //=========================================================================
    // SUMMARY
    //      The Time object contains hours, minutes, and seconds,
    //       
    // RESOURCES
    //      None
    //=========================================================================
    class Time
    {
    public:
        //---------------------------------------------------------------------
        // SUMMARY
        //      Constructor.  Creates a Time object
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      hours
        //          Hours of the object
        //      minutes
        //          Minutes of the object
        //      seconds
        //          Seconds of the object
        //
        // RETURNS
        //      Nothing
        //---------------------------------------------------------------------
        Time(int hours, int minutes, int seconds);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Add current Time together and returns the total number of 
        //      seconds
        //
        // RESOURCES
        //      None
        //
        // PARAMETERS
        //      None
        //
        // RETURNS
        //      The total amount of seconds in the Time object
        //---------------------------------------------------------------------
        int getTotalTimeAsSeconds() const;

        //---------------------------------------------------------------------
        // SUMMARY
        //      Overloads the '+=' operator to add two Time objects together
        //
        // RESOURCES
        //      none
        //
        // PARAMETERS
        //      &rhs
        //          reference to a Time object we will be adding to the lhs
        //          Time object
        //
        // RETURNS
        //      updated Time object
        //---------------------------------------------------------------------
        Time &operator+=(const Time &rhs);

        //---------------------------------------------------------------------
        // SUMMARY
        //      Overloads the '<<' operator to output the Time in a date format
        //
        // RESOURCES
        //      none
        //
        // PARAMETERS
        //      &out
        //          reference to output stream we are writing to
        //      &source
        //          reference to a Time object we will be printing
        //
        // RETURNS
        //      ostream we are writing to
        //---------------------------------------------------------------------
        friend ostream &operator<<(ostream &out, const Time &source);

    private:
        int seconds;
    };

    // Forward declarations
    ostream &operator<<(ostream &out, const Time &source);
}

#endif