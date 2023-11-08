// Jose Medrano
// jcdrano@gmail.com
// C/C++ Programming III : Intermediate Programming with Objects
// 175925, Professor Mitchell
// 09/26/23
// Homework 1
// Win10
// Visual Studio 2022
// This program creates a Date class and exercises different methods to return 
// dates and set new dates.

#include <iostream>
using namespace std;

class Date
{
private:
    int day, month, year;
public:
    Date(int day, int month, int year) {
        this->day = day;

        // Check for invalid month
        if (1 <= month && month <= 12) {
            this->month = month;
        }
        else {
            this->month = 1;
            cerr << "Attempt to set invalid month value. Please enter values "
                "between 1-12.\n";
        }
        
        this->year = year;
        
    };

    int getDay() {
        return day;
    };

    int getMonth() {
        return month;
    };

    int getYear() {
        return year;
    };

    void setDay(int newDay) {
        this->day = newDay;
    };

    void setMonth(int newMonth) {
        // Check for invalid month
        if (1 <= month && month <= 12) {
            this->month = newMonth;
        }
        else {
            this->month = 1;
            cerr << "Attempt to set invalid month value. Please enter values "
                "between 1-12.\n" << flush;
        }
    };

    void setYear(int newYear) {
        this->year = newYear;
    };

    void display() {
        cout << month << '/' << day << '/' << year << '\n';
    };
};

const int DAY = 26;
const int MONTH = 9;
const int YEAR = 2023;
const int TEST_NUM = 10;
const int TEST_ERR = 100;

int main() {
    Date today(DAY, MONTH, YEAR);
    
    cout << "Given date is ";
    today.display();
     
    // Test getter functions
    cout << "Testing getter functions \n" << today.getDay() << '\n' << 
        today.getMonth() << '\n' << today.getYear() << '\n';

    // Test setter functions
    cout << "Testing setter functions \n";
    today.setDay(TEST_NUM);
    today.display();

    today.setMonth(TEST_NUM);
    today.display();

    today.setYear(TEST_NUM);
    today.display();

    // Test invalid month selection
    cout << "Testing error month entry" << endl;
    today.setMonth(TEST_ERR);

    return 0;
}