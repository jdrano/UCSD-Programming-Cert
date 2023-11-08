// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/17/23
// C1A7E1_main.cpp
// Win10
// Visual Studio 2022
// 

#include <iostream>
#include <iomanip>
#include "C1A7E1_MyTime.h"
using namespace std;

MyTime *DetermineElapsedTime(const MyTime *start, const MyTime *end);

int main()
{
    const int NUM_OF_LOOP = 3;

    cout << setfill('0');

    // Prompt user to input data for start and end times until hitting max
    for (int user_input = 0; user_input < NUM_OF_LOOP; user_input++) {
        MyTime start, end;
        char delim = ':';
        cout << "Enter space-separated start/stop times in HH:MM:SS format : ";

        cin >> start.hours >> delim >> start.minutes >> delim >> start.seconds
            >> end.hours >> delim >> end.minutes >> delim >> end.seconds;
        
        MyTime *difference = DetermineElapsedTime(&start, &end);

        cout << "The time elapsed from " << setw(2) << 
            start.hours << ":" << setw(2) <<
            start.minutes << ":" << setw(2) << 
            start.seconds << " to " << setw(2) << 
            end.hours << ":" << setw(2) << 
            end.minutes << ":" << setw(2) << 
            end.seconds << " is " << setw(2) << 
            difference->hours << ":" << setw(2) << 
            difference->minutes << ":" << setw(2) << 
            difference->seconds << "\n";
    }

    return 0;
}
