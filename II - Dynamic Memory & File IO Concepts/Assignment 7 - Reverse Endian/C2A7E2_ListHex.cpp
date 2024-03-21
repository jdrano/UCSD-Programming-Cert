//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/27/24
// C2A7E2_ListHex.cpp
// Win10
// Visual Studio 2022
//
// Reads in every line of an input file and prints out the hex pairs of the
// bytes read in.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void ListHex(ifstream &inFile, int bytesPerLine)
{
    int count = 0;
    char byte;

    cout << setfill('0');

    // Read all data in txt file
    while (inFile.read(&byte, sizeof(byte)))
    {
        // Print space if not initial point
        if (count != 0)
        {
            cout << ' ';
        }

        // Print converted hex values
        cout << hex << setw(2) << (int)(unsigned char)byte;
        count++;

        if (count == bytesPerLine)
        {
            cout << '\n';
            count = 0;
        }
    }
}