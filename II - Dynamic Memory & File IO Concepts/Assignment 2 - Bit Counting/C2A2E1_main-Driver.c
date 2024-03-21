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

#include "C2A2E1_CountBitsM.h"

#define ARRAY_ELEMENTS 25

int CountIntBitsF(void);

int main(void)
{
   //lint -e550 -e754
   char cArray[ARRAY_ELEMENTS];
   double dArray[ARRAY_ELEMENTS];
   long double xyz;
   typedef struct test {long double x; float y; struct test *p;} TEST;

   // Test the function version.
   printf("Implementation-dependent bit widths:\n\n");
   printf("   From CountIntBitsF:\n");
   printf("      Type 'int'         -> %d\n\n", CountIntBitsF());

   // Test the macro version.
   printf("   From CountBitsM:\n");
   printf("      Type 'char'        -> %d\n", CountBitsM(char));
   printf("      Type 'short'       -> %d\n", CountBitsM(short));
   printf("      Type 'int'         -> %d\n", CountBitsM(int));
   printf("      Type 'long'        -> %d\n", CountBitsM(long));
   printf("      Type 'float'       -> %d\n", CountBitsM(float));
   printf("      Type 'double'      -> %d\n", CountBitsM(double));
   printf("      Type 'long double' -> %d\n", CountBitsM(long double));
   printf("\n");
   //lint -e719
   printf("      printf return      -> %d\n", CountBitsM(printf("")));
   //lint +e719
   printf("      'A'                -> %d\n", CountBitsM('A'));
   printf("      2000000+8000000    -> %d\n", CountBitsM(2000000 + 8000000));
   printf("      xyz                -> %d\n", CountBitsM(xyz));
   printf("      cArray             -> %d\n", CountBitsM(cArray));
   printf("      dArray             -> %d\n", CountBitsM(dArray));
   printf("      TEST               -> %d\n", CountBitsM(TEST));
   printf("\n");

   return EXIT_SUCCESS;
}
#endif
