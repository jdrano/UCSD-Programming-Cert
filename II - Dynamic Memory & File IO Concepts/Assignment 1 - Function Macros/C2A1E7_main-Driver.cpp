#define INSTRUCTOR_FILE    // DO NOT DEFINE THIS MACRO IN ANY FILES YOU CREATE

/***  YOU DO NOT NEED TO UNDERSTAND THE CODE IN THIS FILE TO WRITE YOURS  ***/

/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/
/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/
/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/

//****************************************************************************
// Everything in this file was written to help test/verify your code and must
// not be altered in any way.  Do not rename this file or copy anything from
// it into your file(s).  This file does not necessarily represent good coding
// technique, proper formatting/style, or meet the requirements your code must
// meet.  You do not need to understand the code in this file to write yours.
//****************************************************************************
#ifdef INSTRUCTOR_FILE

//
// Unit tests
//

#include <iostream>
#include <cstring>
using namespace std;
#include "C2A1E7_Employee.h"

constexpr int DEFAULT_AGE = 25;
const char* const TEST_NAME = "Elmer Fudd";
constexpr int TEST_AGE = 1234567890;
constexpr float TEST_RAISE = 3000.24F;
constexpr double TEST_SALARY = 8223372036854774800.0;

int main()
{
    int tests = 0;
    int errors = 0;

    // Declare an Employee variable.
    Employee employee;

    // Test setting and getting of employee's age.
    int ageReturn, ageOutVar;
    // Default age
    employee.Set();
    ageReturn = employee.Get(ageOutVar);
    ++tests;
    if (ageReturn != DEFAULT_AGE)
    {
        cerr << "ERROR: Either Set (w/no argument) failed to set the "
            "employee's age to its default value of " << DEFAULT_AGE
            << " or Get failed to return it.\n\n";
        ++errors;
    }
    // Specified age
    employee.Set(TEST_AGE);
    ageReturn = employee.Get(ageOutVar);
    ++tests;
    if (ageReturn != TEST_AGE)
    {
        cerr << "ERROR: Either Set failed to set the employee's "
            "age to " << TEST_AGE << " or Get failed to "
            "return it.\n\n";
        ++errors;
    }
    ++tests;
    if (ageOutVar != TEST_AGE)
    {
        cerr << "ERROR: Get failed to assign the employee's age of "
            << TEST_AGE << " to the variable passed to it.\n\n";
        ++errors;
    }

    // Test setting and getting of employee's raise.
    float raiseReturn, raiseOutVar;
    // Specified raise
    employee.Set(TEST_RAISE);
    raiseReturn = employee.Get(raiseOutVar);
    ++tests;
    if (raiseReturn != TEST_RAISE)
    {
        cerr << "ERROR: Either Set failed to set the employee's "
            "raise to " << TEST_RAISE << " or Get failed to "
            "return it.\n\n";
        ++errors;
    }
    ++tests;
    if (raiseOutVar != TEST_RAISE)
    {
        cerr << "ERROR: Get failed to assign the employee's raise of "
            << TEST_RAISE << " to the variable passed to it.\n\n";
        ++errors;
    }

    // Test setting and getting of employee's salary.
    double salaryReturn, salaryOutVar;
    // Specified salary
    employee.Set(&TEST_SALARY);
    salaryReturn = employee.Get(&salaryOutVar);
    ++tests;
    if (salaryReturn != TEST_SALARY)
    {
        cerr << "ERROR: Either Set failed to set the employee's "
            "salary to " << TEST_SALARY << " or Get failed "
            "to return it.\n\n";
        ++errors;
    }
    ++tests;
    if (salaryOutVar != TEST_SALARY)
    {
        cerr << "ERROR: Get failed to assign the employee's salary of "
            << TEST_SALARY << " into the address specified by the variable "
            "passed to it.\n\n";
        ++errors;
    }

    // Test setting and getting of employee's name.
    char* nameReturn, * nameOutVar;
    // Make a copy of the test name at a different address in case the programmer
    // only does a shallow copy of the pointer.
    size_t nameLength = strlen(TEST_NAME) + 1;
    char* testName = new char[nameLength];
    memcpy(testName, TEST_NAME, nameLength);

    // Specified name
    employee.Set(testName);
    // Delete name from memory programmer should have copied.
    testName[0] = '\0';
    nameReturn = employee.Get(&nameOutVar);
    ++tests;
    if (strcmp(nameReturn, TEST_NAME))
    {
        cerr << "ERROR: Either Set failed to set the employee's "
            "name to " << TEST_NAME << " or Get failed "
            "to return a pointer to it.\n\n";
        ++errors;
    }
    ++tests;
    if (strcmp(nameOutVar, TEST_NAME))
    {
        cerr << "ERROR: Get failed to assign the address of the "
            "employee's name, " << TEST_NAME << ", into the address "
            "specified by the variable passed to it.\n\n";
        ++errors;
    }

    delete[] testName;
    delete[] nameReturn;

    const char* plural = errors != 1 ? "s" : "";
    if (errors)
        cerr << '\n';
    cerr << "C2A1E7: " << tests << " tests " << errors << " error"
        << plural << ".\n\n";

    return 0;
}
#endif
