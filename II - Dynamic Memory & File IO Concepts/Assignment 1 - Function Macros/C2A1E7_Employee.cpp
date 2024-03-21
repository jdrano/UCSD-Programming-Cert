//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/11/24
// C2A1E7_Employee.cpp
// Win10
// Visual Studio 2022
//
// C2A1E7_Employee.cpp contains the declaration for the setter function of the 
// name.
//

#include <cstring>
#include "C2A1E7_Employee.h"
using namespace std;

//---------------------------------------------------------------------
// SUMMARY
//      Sets the name of the passed through parameter to this object's name. 
//
// RESOURCES
//      None
//
// PARAMETERS
//      name
//          Name of the employee to be reassigned.
//      
// RETURNS
//      Nothing
//---------------------------------------------------------------------
void 
Employee::Set(const char *name) {
    size_t length = strlen(name) + 1;
    this->name_ = new char[length];
    memcpy(this->name_, name, length);
}
