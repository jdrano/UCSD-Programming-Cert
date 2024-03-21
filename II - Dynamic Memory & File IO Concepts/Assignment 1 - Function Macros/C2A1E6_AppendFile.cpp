//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/11/24
// C2A1E6_AppendFile.cpp
// Win10
// Visual Studio 2022
//
// This file contains a function that appends to files together, both text and
// binary data.
//

#include <iostream>
#include <fstream>
using namespace std;

const int BUFSIZE = 256;

int AppendFile(const char *inFile, const char *outFile) {
    // To contain a whole line
    char buf[BUFSIZE]; 

    ifstream source(inFile, ios_base::binary);
    // Check for valid file
    if (!source.is_open()) {
        cerr << "Error opening inFile.\n";
        return -1;
    }

    ofstream destination(outFile, ios_base::binary | ios_base::app);
    // Check for valid file
    if (!destination.is_open()) {
        source.close();
        cerr << "Error opening outFile.\n";
        return -1;
    }

    // Continually append the source file to the end of the destination file
    while (source.read(buf, sizeof(buf[0]))) {
        destination.write(buf, sizeof(buf[0]));
    }

    source.close();
    destination.close();
    return 0;
}