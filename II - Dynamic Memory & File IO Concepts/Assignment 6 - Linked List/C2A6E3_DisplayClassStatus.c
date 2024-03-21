//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/18/24
// C2A6E3_DisplayClassStatus.c
// Win10
// Visual Studio 2022
//
// This file contains functions to practice qsort and bsearch.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Compare(const void *elemA, const void *elemB)
{
    return strcmp(*(char **)elemA, *(char **)elemB);
}

void SortStudents(const char *studentList[], size_t studentCount)
{
    qsort(studentList, studentCount, sizeof(char *), Compare);
}

void DisplayClassStatus(const char *registrants[], size_t registrantCount,
    const char *attendees[], size_t attendeeCount)
{
    printf("Not present:\n");
    // Find registrands that did not attend
    for (size_t curr_person = 0; curr_person < registrantCount; curr_person++)
    {
        void *attended = bsearch(&registrants[curr_person], attendees,
            attendeeCount, sizeof(registrants[0]), Compare);

        // Print registrand that did not attend
        if (!attended)
        {
            printf("    %s\n", registrants[curr_person]);
        }
    }

    printf("Not registered:\n");
    // Find attendees that did not register
    for (size_t curr_person = 0; curr_person < attendeeCount; curr_person++)
    {
        void *registered = bsearch(&attendees[curr_person], registrants,
            registrantCount, sizeof(registrants[0]), Compare);

        // Print attendee that did not register
        if (!registered)
        {
            printf("    %s\n", attendees[curr_person]);
        }
    }
}
