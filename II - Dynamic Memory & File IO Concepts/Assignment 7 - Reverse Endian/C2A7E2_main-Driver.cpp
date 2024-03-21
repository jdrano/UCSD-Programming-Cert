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
#include <cstdio>
#include <fstream>
#include <iostream>
using namespace std;

constexpr int ARGUMENTS_EXPECTED = 3;   // command line args expected
constexpr int INFILE_ARG_IX = 1;        // index of input file name
constexpr int BYTE_COUNT_ARG_IX = 2;    // index of line count

void OpenFileBinary(const char* fileName, ifstream& inFile);
void ListHex(ifstream& inFile, int bytesPerLine);

int main(int argc, char* argv[])
{
    if (argc != ARGUMENTS_EXPECTED)  // check number of command line args
    {
        cerr << "Syntax is: pgmName fileName bytesPerLine\n";
        exit(EXIT_FAILURE);
    }

    ifstream inFile;
    OpenFileBinary(argv[INFILE_ARG_IX], inFile);
    cout << "Hex dump of file " << argv[INFILE_ARG_IX] << " with " <<
        atoi(argv[BYTE_COUNT_ARG_IX]) << " bytes per line:\n";
    ListHex(inFile, atoi(argv[BYTE_COUNT_ARG_IX]));
    inFile.close();
    cout << '\n';

    return EXIT_SUCCESS;
}
#endif
