// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 8/17/23
// C1A7E1_MyTime.h
// Win10
// Visual Studio 2022
// Contains the struct for the MyTime object which holds 3 int 
// variables: hours, minutes, seconds.

#ifndef C1A7E1_MYTIME_H
#define C1A7E1_MYTIME_H

struct MyTime {
    int hours, minutes, seconds;
}; 

MyTime *DetermineElapsedTime(const MyTime *start, const MyTime *end);

#endif