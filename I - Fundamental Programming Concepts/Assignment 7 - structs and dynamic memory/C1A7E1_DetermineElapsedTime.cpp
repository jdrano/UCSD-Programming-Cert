// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/17/23
// C1A7E1_DetermineElapsedTime.cpp
// Win10
// Visual Studio 2022
// The DetermineElapsedTime takes 2 MyTime objects and returns a pointer to an
// automatic MyTime object that holds the difference in time between the start
// and end times.

#include "C1A7E1_MyTime.h"

MyTime *DetermineElapsedTime(const MyTime *start, const MyTime *end)
{
    const long int SEC_IN_HOUR = 3600, MAX_MINUTES_SECONDS = 60; 
    const long int SEC_IN_DAY = 86400, HOURS_IN_DAY = 24;
    static MyTime difference;

    long int start_total_secs = (start->hours * MAX_MINUTES_SECONDS *
        MAX_MINUTES_SECONDS) + (start->minutes * MAX_MINUTES_SECONDS)
        + start->seconds; 
    long int end_total_secs = (end->hours * MAX_MINUTES_SECONDS *
        MAX_MINUTES_SECONDS) + (end->minutes * MAX_MINUTES_SECONDS)
        + end->seconds;
    
    // Set difference in times to 24 hours if both given times are 12am
    if (start_total_secs == end_total_secs && start_total_secs == 0) {
        difference.hours = HOURS_IN_DAY;
        difference.minutes = 0;
        difference.seconds = 0;

    // Adjust for end time being earlier in the day than the start
    } else if (start_total_secs > end_total_secs) {
        difference.hours = (SEC_IN_DAY - start_total_secs + end_total_secs) /
            SEC_IN_HOUR;
        difference.minutes = ((SEC_IN_DAY - start_total_secs + end_total_secs) %
            SEC_IN_HOUR) / MAX_MINUTES_SECONDS;
        difference.seconds = ((SEC_IN_DAY - start_total_secs + end_total_secs) %
            SEC_IN_HOUR) % MAX_MINUTES_SECONDS;

    // Set difference hours, minutes, seconds
    } else {
        difference.hours = (end_total_secs - start_total_secs) /
            SEC_IN_HOUR;
        difference.minutes = ((end_total_secs - start_total_secs) %
            SEC_IN_HOUR) / MAX_MINUTES_SECONDS;
        difference.seconds = ((end_total_secs - start_total_secs) %
            SEC_IN_HOUR) % MAX_MINUTES_SECONDS;
    }

    return &difference;
}
