//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/17/24
// C2A2E1_CountBitsM.h
// Win10
// Visual Studio 2022
//
// File contains a macro that returns the bits in a byte of data that is
// passed through the parameter if CountBitsM.
//

#ifndef C2A2E1_COUNTBITSM_H
#define C2A2E1_COUNTBITSM_H

#include <limits.h>

#define CountBitsM(objectOrType) ((int)sizeof(objectOrType) * CHAR_BIT)
#endif 
