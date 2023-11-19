// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// Time.cpp
// Win10
// Visual Studio 2022
// Declarations for Complex class.

#include "Time.h"
#include <iostream>

using namespace std;
using namespace Project2;

const int SECS_IN_MIN = 60;
const int SECS_IN_HOUR = 3600;

// Constructors
Project2::Time::Time(int hours, int minutes, int seconds) {
    this->seconds = (hours * SECS_IN_HOUR) + (minutes * SECS_IN_MIN) + seconds;
}

// Getter
int
Project2::Time::getTotalTimeAsSeconds() const {
    return seconds;
}

Time& 
Project2::Time::operator+=(const Time &rhs) {
    this->seconds += rhs.getTotalTimeAsSeconds();
    return *this;
}

ostream&
Project2::operator<<(ostream &out, const Time &source) {
    int TimeLeft = source.getTotalTimeAsSeconds();

    int hours = TimeLeft / SECS_IN_HOUR;
    TimeLeft %= SECS_IN_HOUR;

    int minutes = TimeLeft / SECS_IN_MIN;
    TimeLeft %= SECS_IN_MIN;

    int seconds = TimeLeft;

    out << hours << "h:" << minutes << "m:" << seconds << "s";

    return out;
}