//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/09/24
// C2A1E1_Macros.h
// Win10
// Visual Studio 2022
//
// Contains macros for product, negate, and counting the size of an array 
// functions.
//

#ifndef C2A1E1_MACROS_H
#define C2A1E1_MACROS_H

#define Product(productA, productB) ((productA) * (productB))
#define Negate(inverse) (-(inverse))
#define Elements(count) (sizeof(count) / sizeof((count)[0]))
#endif
