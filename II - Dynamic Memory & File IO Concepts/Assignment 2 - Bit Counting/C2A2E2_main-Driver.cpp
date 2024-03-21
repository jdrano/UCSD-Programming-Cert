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

#include <cstdlib>
#include <iostream>
using namespace std;

unsigned Rotate(unsigned object, int count);

int main()
{
   //
   // Note: Displaying rotation or shift counts in any radix other than decimal
   // is difficult to interpret, but displaying bit patterns in decimal is
   // virtually useless.
   //
   cout << hex;
   // Test several different cases.
   cout << "0x5 rotated right by 1 bit is 0x" <<
      Rotate(0x5, 1) << "\n\n";
   cout << "0x5 rotated left by 1 bit is 0x" <<
      Rotate(0x5, -1) << "\n\n";
   cout << "0x5 rotated right by 64 bits is 0x" <<
      Rotate(0x5, 64) << "\n\n";
   cout << "0x8765 rotated left by 64 bits is 0x" <<
      Rotate(0x8765, -64) << "\n\n";
   cout << "0x8765 rotated right by 3217 bits is 0x" <<
      Rotate(0x8765, 3217) << "\n\n";
   cout << "0x8765 rotated left by 3217 bits is 0x" <<
      Rotate(0x8765, -3217) << "\n\n";

   return EXIT_SUCCESS;
}
#endif
