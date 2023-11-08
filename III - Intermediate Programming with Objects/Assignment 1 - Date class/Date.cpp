// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 10/10/23
// Date.cpp
// Win10
// Visual Studio 2022
// Definitions for Date class.

#include <iostream>
#include <ctime>
#include "Date.h"

using namespace std;

// Constructor defines member data using current system time.
JoseMedrano::Date::Date() {
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);

    this->month = 1 + newtime.tm_mon;
    this->day = newtime.tm_mday;
    this->year = 1900 + newtime.tm_year;
}

// Param Constructor
JoseMedrano::Date::Date(int month, int day, int year) {
    // Check for illegal month
    if (month < 1 || 12 < month) {
        cerr << "Month not in range. Range is 1-12 inclusive.\n";
        this->month = -1;
    }
    else {
        this->month = month;
    }

    // Check for illegal day
    if (day < 0) {
        cerr << "Day must be greater than 0.\n";
        this->day = -1;
    }
    
    // Check for February
    if (month == 2) {
        if (day > 29) {
            cerr << "Illegal day. Does not exist in given month.\n";
            this->day = -1;
        }
        else {
            this->day = day;
        }
    }
    
    // Check for months with 30 days
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            cerr << "Illegal day. Does not exist in given month.\n";
            this->day = -1;
        }
        else {
            this->day = day;
        }
    }

    // Check for remaining months with 31 days
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || 
        month == 10 || month == 12) {
        if (day > 31) {
            cerr << "Illegal day. Does not exist in given month.\n";
            this->day = -1;
        }
        else {
            this->day = day;
        }
    }

    // Check for illegal year
    if (year < 0) {
        cerr << "Year must be greater than 0.\n";
        this->year = -1;
    }
    else {
        this->year = year;
    }
}

// Displays the date of the date object in month/day/year format.
void
JoseMedrano::Date::display() const {
    cout << getMonth() << "/" << getDay() << "/" << getYear() << "\n";
}

// Changes day of Date.
void
JoseMedrano::Date::setDay(int day) {
    // Check for illegal day
    if (day < 0) {
        cerr << "Day must be greater than 0.\n";
        this->day = -1;
    }
    else {
        this->day = day;
    }
}

// Changes month of Date
void
JoseMedrano::Date::setMonth(int month) {
    // Check for illegal month
    if (month < 1 || 12 < month) {
        cerr << "Month not in range. Range is 1-12 inclusive.\n";
        this->month = -1;
    }
    else {
        this->month = month;
    }
}

// Changes year of Date
void
JoseMedrano::Date::setYear(int year) {
    // Check for illegal year
    if (year < 0) {
        cerr << "Year must be greater than 0.\n";
        this->year = -1;
    }
    else {
        this->year = year;
    }
}