//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/27/24
// C2A7E2_OpenFileBinary.cpp
// Win10
// Visual Studio 2022
//
// Opens a file in binary.
//

#include <iostream>
#include <fstream>
using namespace std;

void OpenFileBinary(const char *filename, ifstream &inFile)
{
    inFile.open(filename, ios::binary);

    // Check for error opening file
    if (!inFile.is_open())
    {
        cerr << "Error opening file: " << filename << '\n';
        exit(1);
    }
}