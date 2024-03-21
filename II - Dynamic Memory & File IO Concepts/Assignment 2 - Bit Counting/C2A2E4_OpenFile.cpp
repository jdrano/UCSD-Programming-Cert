//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/18/24
// C2A2E4_OpenFile.cpp
// Win10
// Visual Studio 2022
//
// OpenFile is a function that attempts to open "filename" and assigns it to 
// inFile. If not successful we quit with an exit code.
//

#include <fstream>
#include <iostream>

using namespace std;

void 
OpenFile(const char *filename, ifstream &inFile) {
    inFile = ifstream(filename);
    // Check for valid file
    if (!inFile.is_open()) {
        cerr << "Error opening " << filename << ".\n";
        exit(1);
    }
    return;
}