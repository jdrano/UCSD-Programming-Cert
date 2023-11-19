// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 11/24/23
// DataRecorder.cpp
// Win10
// Visual Studio 2022
// Declarations for DataRecorder class.

#include "DataRecorder.h"
#include <sstream>
#include <iomanip>

using namespace std;
using namespace Project2;


// Constructors
Project2::DataRecorder::DataRecorder(ostream &out) : out(out) 
{

}

string
Project2::DataRecorder::log(Time Timestamp, string sensorName, 
    double sensorVoltage, string sensorUnits) 
{
    string log;

    // Deal with rounding volts palcement
    ostringstream voltsStream;
    voltsStream << fixed << setprecision(2) << sensorVoltage;
    string volts = voltsStream.str();



    // Turn Timestamp into a string
    ostringstream dateStream;
    dateStream << Timestamp;
    string date = dateStream.str();

    // Assemble the log string
    log += date + " - ";

    log += sensorName + " - ";

    log +=  volts + " ";

    log += sensorUnits + '\n';

    out << log;
    return log;
}
