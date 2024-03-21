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
#include <fstream>
#include <iostream>
using namespace std;

const char * const FILENAME = "TestFile2.txt";

void OpenFile(const char *fileName, ifstream &inFile);
int Reverse(ifstream &inFile, const int level);

int main()
{
   ifstream inFile;
   int thisSeparator;

   OpenFile(FILENAME, inFile);
   while ((thisSeparator = Reverse(inFile, 1)) != EOF)
      cout.put(char(thisSeparator));
   inFile.close();
   return EXIT_SUCCESS;
}
#endif
