// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/16/23
// C1A6E3_GetSubstring.c
// Win10
// Visual Studio 2022
// GetSubstring returns the start of a substring from a given source string. 
// Starting from the start parameter in the source string, we iterate count 
// amount of times while assigning each char to our result string.

char *GetSubstring(const char source[], int start, int count, char result[]) 
{
    char *result_ptr = result;

    // Check to see if source is null entry or if count is empty
    if (*source == '\0' || count <= 0) {
        *result = '\0';
        return result;
    }

    // Iterate over source string until hitting starting point
    while (start > 0) {
        source++;
        start--;
    }

    // Copy section of source into result until hitting null or count = 0
    while (*source != '\0' && count > 0) {
        *result_ptr = *source;
        result_ptr++;
        source++;
        count--;
    }

    *result_ptr = '\0';

    return result;
}
