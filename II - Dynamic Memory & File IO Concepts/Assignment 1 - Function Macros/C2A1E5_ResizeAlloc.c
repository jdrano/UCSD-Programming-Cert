//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/11/24
// C2A1E5_ResizeAlloc.c
// Win10
// Visual Studio 2022
//
// This file contains a function whose purpose is to reallocate the necessary
// amount of memory of a returned void ptr, based on the sizes passed through
//

#include <stdlib.h>
#include <string.h>

void *ResizeAlloc(void *pOld, size_t newSize, size_t oldSize) {
    // Check for NULL size
    if (newSize == 0) {
        return NULL;
    }
    else {
        void *vp = malloc(newSize);
        // Check for positive mem allocation
        if (vp == NULL) {
            return NULL;
        }
        // Check if ptr we are copying is NULL
        else if (pOld == NULL) {
            return vp;
        }
        else {
            // Check to find correct size for copy
            if (newSize > oldSize) {
                memcpy(vp, pOld, oldSize);
            }
            else {
                memcpy(vp, pOld, newSize);
            }
            free(pOld);
        } 

        return vp;
    }
}
