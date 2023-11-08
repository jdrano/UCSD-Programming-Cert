// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 174273, Professor Mitchell
// 08/15/23
// C1A6E2_MyStrcmp.c
// Win10
// Visual Studio 2022
// MyStrcmp acts as a possible substitute to strcmp. Takes in two const char
// pointers to strings and compares to see if they are the same. Returns an int
// to signal if the lexicographical values differ at any point.

int MyStrcmp(const char *s1, const char *s2)
{
    // Compare characters in string until hitting a null character
    while (*s1 != '\0' || *s2 != '\0') {
        // return 0 (true) if current char is null and every char matched
        if (*s1 == *s2 && *s1 == '\0') {
            return 0;
        }
        // return -1 if s1 is lexicographically smaller
        else if (*s1 < *s2) {
            return -1;
        }
        // return 1 if s1 is lexicographically larger
        else if (*s1 > *s2) {
            return 1;
        }

        s1++;
        s2++;
    }

    // return true if given empty string
    return 0;
}
