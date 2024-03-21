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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "C2A4E2_StorageMap5D.h"

#define D_A 2
#define D_B 3
#define D_C 4
#define D_D 5
#define D_E 6

int main(void)
{
    int ix0, ix1, ix2, ix3, ix4;
    int foo[D_A][D_B][D_C][D_D][D_E];
    double bar[D_A][D_B][D_C][D_D][D_E];
    long big[D_E][D_D][D_C][D_B][D_A];
    float deal[D_E][D_D][D_C][D_B][D_A];

    // seed random # generator
    srand((unsigned)time(NULL));
    // store all values before testing any
    for (ix0 = 0; ix0 < D_A; ++ix0)
        for (ix1 = 0; ix1 < D_B; ++ix1)
            for (ix2 = 0; ix2 < D_C; ++ix2)
                for (ix3 = 0; ix3 < D_D; ++ix3)
                    for (ix4 = 0; ix4 < D_E; ++ix4)
                    {
                        foo[ix0][ix1][ix2][ix3][ix4] = rand();
                        bar[ix0][ix1][ix2][ix3][ix4] = rand() + rand() / 321.0;
                    }

    for (ix0 = 0; ix0 < D_E; ++ix0)
        for (ix1 = 0; ix1 < D_D; ++ix1)
            for (ix2 = 0; ix2 < D_C; ++ix2)
                for (ix3 = 0; ix3 < D_B; ++ix3)
                    for (ix4 = 0; ix4 < D_A; ++ix4)
                    {
                        big[ix0][ix1][ix2][ix3][ix4] = rand();
                        deal[ix0][ix1][ix2][ix3][ix4] = rand() + rand() / 123.0F;
                    }

    // Test all stored values.
    for (ix0 = 0; ix0 < D_A; ++ix0)
        for (ix1 = 0; ix1 < D_B; ++ix1)
            for (ix2 = 0; ix2 < D_C; ++ix2)
                for (ix3 = 0; ix3 < D_D; ++ix3)
                    for (ix4 = 0; ix4 < D_E; ++ix4)
                    {
                        if (StorageMap5D((int*)foo, ix0, ix1, ix2, ix3, ix4,
                            D_B, D_C, D_D, D_E) != foo[ix0][ix1][ix2][ix3][ix4])
                        {
                            fprintf(stderr, "Error: foo[%d][%d][%d][%d][%d]\n",
                                ix0, ix1, ix2, ix3, ix4);
                            return EXIT_FAILURE;
                        }
                        if (StorageMap5D((double*)bar, ix0, ix1, ix2, ix3, ix4,
                            D_B, D_C, D_D, D_E) != bar[ix0][ix1][ix2][ix3][ix4])
                        {
                            fprintf(stderr, "Error: bar[%d][%d][%d][%d][%d]\n",
                                ix0, ix1, ix2, ix3, ix4);
                            return EXIT_FAILURE;
                        }
                    }

    for (ix0 = 0; ix0 < D_E; ++ix0)
        for (ix1 = 0; ix1 < D_D; ++ix1)
            for (ix2 = 0; ix2 < D_C; ++ix2)
                for (ix3 = 0; ix3 < D_B; ++ix3)
                    for (ix4 = 0; ix4 < D_A; ++ix4)
                    {
                        if (StorageMap5D((long*)big, ix0, ix1, ix2, ix3, ix4,
                            D_D, D_C, D_B, D_A) != big[ix0][ix1][ix2][ix3][ix4])
                        {
                            fprintf(stderr, "Error: big[%d][%d][%d][%d][%d]\n",
                                ix0, ix1, ix2, ix3, ix4);
                            return EXIT_FAILURE;
                        }
                        if (StorageMap5D((float*)deal, ix0, ix1, ix2, ix3, ix4,
                            D_D, D_C, D_B, D_A) != deal[ix0][ix1][ix2][ix3][ix4])
                        {
                            fprintf(stderr, "Error: deal[%d][%d][%d][%d][%d]\n",
                                ix0, ix1, ix2, ix3, ix4);
                            return EXIT_FAILURE;
                        }
                    }

    --ix0;
    --ix1;
    --ix2;
    --ix3;
    --ix4;
    if (StorageMap5D((long*)big, ix0 + 1 - 1, ix1 + 2 - 2, ix2 + 3 - 3,
        ix3 + 4 - 4, ix4 + 5 - 5, D_D + 4 - 4, D_C + 3 - 3, D_B + 2 - 2,
        D_A + 1 - 1) !=
        big[ix0][ix1][ix2][ix3][ix4])
    {
        fprintf(stderr, "Error 2: big[%d][%d][%d][%d][%d]\n",
            ix0, ix1, ix2, ix3, ix4);
        return EXIT_FAILURE;
    }

    printf("Assignment 4 Exercise 2: No errors detected!\n");
    return EXIT_SUCCESS;
}
#endif
