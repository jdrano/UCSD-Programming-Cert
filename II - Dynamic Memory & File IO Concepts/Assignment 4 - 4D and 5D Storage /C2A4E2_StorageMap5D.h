//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/02/24
// C2A4E2_StorageMap5D.h
// Win10
// Visual Studio 2022
//
// This file contains a macro that can access a specified index of a 5D array
//

#ifndef C2A4E2_STORAGEMAP5D_H
#define C2A4E2_STORAGEMAP5D_H

#define StorageMap5D(ptr, idx0, idx1, idx2, idx3, idx4, dim1, dim2, dim3, dim4)\
(*((ptr) + \
(idx0) * (dim1) * (dim2) * (dim3) * (dim4) + \
(idx1) * (dim2) * (dim3) * (dim4) + \
(idx2) * (dim3) * (dim4) + \
(idx3) * (dim4) + \
(idx4)))

#endif
