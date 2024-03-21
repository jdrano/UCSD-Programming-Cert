//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/11/24
// C2A1E7_Employee.h
// Win10
// Visual Studio 2022
//
// C2A1E7_Employee.h contains a variety of getter and setter functions for data 
// members customary of employees.
//

#ifndef C2A1E7_EMPLOYEE_H
#define C2A1E7_EMPLOYEE_H

//=========================================================================
// SUMMARY
//      The Employee class contains all data members in regards to a generic
//      work employee.
//       
// RESOURCES
//      None
//=========================================================================
class Employee
{
public:
    //---------------------------------------------------------------------
    // SUMMARY
    //      Constructor.  
    //
    // RESOURCES
    //      None
    //
    // PARAMETERS
    //      None
    //      
    // RETURNS
    //      Nothing
    //---------------------------------------------------------------------
    Employee() {
        name_ = 0;
        age_ = 0;
        raise_ = 0.0;
        salary_ = 0;
    }

    //---------------------------------------------------------------------
    // SUMMARY
    //      Prototype fuunction for name setting.  
    //
    // RESOURCES
    //      None
    //
    // PARAMETERS
    //      None
    //      
    // RETURNS
    //      Nothing
    //---------------------------------------------------------------------
    void Set(const char *name_);

    //---------------------------------------------------------------------
    // SUMMARY
    //      Changes age of employee to passed in parameter. If no parameter
    //      is passed through then the default age will be 25. 
    //
    // RESOURCES
    //      None
    //
    // PARAMETERS
    //      age_
    //          Age to be given to the employee
    //      
    // RETURNS
    //      Nothing
    //---------------------------------------------------------------------
    void Set(int age_ = 25) {
        this->age_ = age_;
    }

    //---------------------------------------------------------------------
    // SUMMARY
    //      Changes the raise of the employee to passed in parameter. 
    //
    // RESOURCES
    //      None
    //
    // PARAMETERS
    //      raise_
    //          Raise to be given to the employee
    //      
    // RETURNS
    //      Nothing
    //---------------------------------------------------------------------
    void Set(const float &raise_) {
        this->raise_ = raise_;
    }

    //---------------------------------------------------------------------
    // SUMMARY
    //      Changes the salary of the employee to passed in parameter. 
    //
    // RESOURCES
    //      None
    //
    // PARAMETERS
    //      salary_
    //          Salary to be given to the employee
    //      
    // RETURNS
    //      Nothing
    //---------------------------------------------------------------------
    void Set(const double *salary_) {
        this->salary_ = *salary_;
    }

    //---------------------------------------------------------------------
    // SUMMARY
    //      Returns the name of the employee. 
    //
    // RESOURCES
    //      None
    //
    // PARAMETERS
    //      name
    //          A pointer to a pointer of the memory address of the
    //          employee.
    //      
    // RETURNS
    //      A char pointer to the name of the employee.
    //---------------------------------------------------------------------
    char *Get(char **name_) {
        return *name_ = this->name_;
    }

    //---------------------------------------------------------------------
    // SUMMARY
    //      Returns the age of the employee. 
    //
    // RESOURCES
    //      None
    //
    // PARAMETERS
    //      age
    //          Value to be returned. 
    //      
    // RETURNS
    //      The age of the employee.
    //---------------------------------------------------------------------
    int Get(int &age_) {
        return age_ = this->age_;
    }

    //---------------------------------------------------------------------
    // SUMMARY
    //      Returns the raise of the employee. 
    //
    // RESOURCES
    //      None
    //
    // PARAMETERS
    //      raise
    //          Value to be returned. 
    //      
    // RETURNS
    //      The raise of the employee.
    //---------------------------------------------------------------------
    float &Get(float &raise_) {
        return raise_ = this->raise_;
    }
        
    //---------------------------------------------------------------------
    // SUMMARY
    //      inline prototype of a getter function for salary.
    //
    // RESOURCES
    //      None
    //
    // PARAMETERS
    //      salary_
    //          Value to be returned. 
    //      
    // RETURNS
    //      The salary of the employee.
    //---------------------------------------------------------------------
    inline double Get(double *salary_);

private:
    char *name_;
    int age_;
    float raise_;
    double salary_;        
};

//---------------------------------------------------------------------
// SUMMARY
//      inline prototype of a getter function for salary.
//
// RESOURCES
//      None
//
// PARAMETERS
//      salary_
//          Value to be returned. 
//      
// RETURNS
//      The salary of the employee.
//---------------------------------------------------------------------
double Employee::Get(double *salary_) {
    return *salary_ = this->salary_;
}

#endif