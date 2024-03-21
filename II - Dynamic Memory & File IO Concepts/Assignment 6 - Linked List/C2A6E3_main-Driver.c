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

#define Elements(array) (sizeof(array)/sizeof((array)[0]))

int Compare(const void* elemA, const void* elemB);
void SortStudents(const char* studentList[], size_t studentCount);
void DisplayClassStatus(const char* registrants[], size_t registrantCount,
    const char* attendees[], size_t attendeeCount);


int main(void)
{
    const char* registrants0[] =
    {
       "Xenon Man", "Wonder Woman", "The Green Lantern", "The Flash"
    };
    const char* attendees0[] =
    {
       "The Flash", "The Green Lantern", "Wonder Woman", "Xenon Man"
    };
    const char* registrants1[] =
    {
       "Al", "Tough Guy", "Mae East", "Bill", "Avenger", "Jo", "Mary",
       "Agitation King", "Elvis", "Zabo The Great", "Slim Jim",
       "Stinky The Clown", "Carl Crumb", "What's On Second", "Aces Wild",
       "Night Flyer"
    };
    const char* attendees1[] =
    {
       "Al", "Tough Guy", "Mae East", "Bill", "Jo", "Mary", "Petty Patty",
       "Elmer Fudd", "Elvis", "Slim Jim", "Stinky The Clown", "Carl Crumb",
       "Ned Nasty", "Who's On First", "Aces Wild", "Night Flyer",
       "Carl Clean"
    };

    // Initial test of comparison function
    if (Compare(&registrants0[1], &registrants0[0]) >= 0 ||
        Compare(&registrants0[0], &registrants0[0]) != 0 ||
        Compare(&registrants0[0], &registrants0[1]) <= 0)
    {
        fprintf(stderr, "Comparison function failed!\n");
        return EXIT_FAILURE;
    }

    // Display status of class #0 before sorting registrants and attendees.
    printf("Class #0 before sorting:\n");
    DisplayClassStatus(registrants0, Elements(registrants0),
        attendees0, Elements(attendees0));
    printf("\n");
    SortStudents(registrants0, Elements(registrants0));
    SortStudents(attendees0, Elements(attendees0));

    // Display status of class #0 after sorting registrants and attendees.
    printf("Class #0 after sorting:\n");
    DisplayClassStatus(registrants0, Elements(registrants0),
        attendees0, Elements(attendees0));
    printf("\n");


    // Display status of class #1 before sorting registrants and attendees.
    printf("Class #1 before sorting:\n");
    DisplayClassStatus(registrants1, Elements(registrants1),
        attendees1, Elements(attendees1));
    printf("\n");
    SortStudents(registrants1, Elements(registrants1));
    SortStudents(attendees1, Elements(attendees1));

    // Display status of class #1 after sorting registrants and attendees.
    printf("Class #1 after sorting:\n");
    DisplayClassStatus(registrants1, Elements(registrants1),
        attendees1, Elements(attendees1));
    printf("\nEnd of Class Reports\n");

    return EXIT_SUCCESS;
}
#endif
