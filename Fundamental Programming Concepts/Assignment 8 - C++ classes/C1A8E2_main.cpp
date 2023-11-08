// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/27/23
// C1A8E2_main.cpp
// Win10
// Visual Studio 2022
// 

#include <iostream>
#include <fstream>
using namespace std;

const int BUFSIZE = 256;
const int ARG_INPUT = 1;
const int ARG_OUTPUT = 2;
const int ARG_SEARCH = 3;
const int ARG_REPLACEMENT = 4;
const int NUM_OF_ARGS = 5;

int main(int argc, char *argv[])
{
    if (argc != NUM_OF_ARGS) {
        cerr << "Correct number of Args not entered. Correct Number is " <<
            NUM_OF_ARGS << '\n';
        exit(EXIT_FAILURE);
    }

    char *input_file = argv[ARG_INPUT];
    char *output_file = argv[ARG_OUTPUT];
    char *search = argv[ARG_SEARCH];
    char *replacement = argv[ARG_REPLACEMENT];
    char buffer[BUFSIZE];

    int length = 0;
    // Count every character in the search string
    while (search[length] != '\0') {
        ++length;
    }

    // Create, test for successful file open for input file
    ifstream input(input_file);
    if (!input.is_open()) {
        cerr << "Couldn't open file " << input_file << '\n';
        exit(EXIT_FAILURE);
    }
    // Create, then test for successful file open for output file
    ofstream output(output_file);
    if (!output.is_open()) {
        cerr << "Couldn't open file " << output_file << '\n';
        exit(EXIT_FAILURE);
    }
    
    // As long as the input file has readable lines, perform string replacement
    while (input.getline(buffer, BUFSIZE)) {
        char *cp1;

        // At every point where the search string is found, add replacement
        for (cp1 = buffer; char *cp2 = strstr(cp1, search);) {
            output.write(cp1, cp2 - cp1);
            output << replacement;
            cp1 = cp2 + length;
        }

        // Finish writing rest of buffer into output file
        for (; *cp1 != '\0'; ++cp1) {
            output.write(cp1, 1);
        }
        output.write("\n", 1); // Add newline
    }

    // Close both files.
    input.close();
    output.close();

    return 0;
}
