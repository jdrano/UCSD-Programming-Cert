// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 10/10/23
// Date.h
// Win10
// Visual Studio 2022
// Date class and member data.

#ifndef DATE_H
#define DATE_H

namespace JoseMedrano
{
    class Date
    {
    public:
        // Constructors
        Date();
        Date(int month, int day, int year);
        
        // Accessors
        inline int getDay() const {
            return day;
        };
        inline int getMonth() const {
            return month;
        };
        inline int getYear() const {
            return year;
        };

        // Mutators
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);

        // Display
        void display() const;

    private:
        int month, day, year;
    };
}

#endif