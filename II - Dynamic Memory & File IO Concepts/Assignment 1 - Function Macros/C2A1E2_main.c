//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/09/24
// C2A1E2_main.c
// Win10
// Visual Studio 2022
//
// This file counts the number of arguments and prints the number of arguments
// and the name of the arguments.
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("%d\n", argc);
    // Loop through every argument and print of arg number and its contents
    for (int curr_arg = 0; curr_arg < argc; curr_arg++) {
        printf("%s\n", argv[curr_arg]);
    }
    return 0;
}
