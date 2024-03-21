//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/17/24
// C2A6E2_SortValues.cpp
// Win10
// Visual Studio 2022
//
// Using the bubble sort algorithm, this function arranges the array from
// greatest to lowest value.
//

float *SortValues(float *first, size_t elements)
{
    bool didSwap;
    float *last = &first[elements - 1];

    // Make a pass looking for valid swaps, if none found continue
    do
    {
        didSwap = false;
        // Make all possible swaps in a single pass
        for (float *current = first; current < last; current++)
        {
            float *fwd_step = current;
            fwd_step++;
            if (*current < *fwd_step)
            {
                float temp = *current;
                *current = *fwd_step;
                *fwd_step = temp;
                didSwap = true;
            }
        }
        --last;
    }
    // Check for swap
    while (didSwap);

    return first;
}