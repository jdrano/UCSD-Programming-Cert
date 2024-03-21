//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/18/24
// C2A3E4_ParseStringFields.c
// Win10
// Visual Studio 2022
//
// This file contains a function that parses through a text document deleting
// characters specified in the delim array and prints the tokens on their
// own lines.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 256
#define DELIM "AEIOUaeiou\t\n"
void ParseStringFields(FILE *fp) {
    char line[BUFSIZE];

    // Read all lines in the file
    while (fgets(line, BUFSIZE, fp) != NULL) {
        char *token = strtok(line, DELIM);

        // Print out all tokens in the line
        while (token != NULL) {
            char *start = token;

            // Skip all leading whitespaces
            while (isspace(*start)) {
                start++;
            }
            printf("%s\n", start);

            token = strtok(NULL, DELIM);
        }
    }
}
