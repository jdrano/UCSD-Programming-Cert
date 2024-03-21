//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/27/24
// C2A7E4_OpenTemporaryFile.c
// Win10
// Visual Studio 2022
//
// Creates a tmpfile.
//

#include <stdio.h>
#include <stdlib.h>

FILE *OpenTemporaryFile(void)
{
    FILE *temp = tmpfile();

    // Check if the tmpfile was created
    if (!temp)
    {
        fprintf(stderr, "Tmpfile could not be created.");
        exit(1);
    }

    return temp;
}
