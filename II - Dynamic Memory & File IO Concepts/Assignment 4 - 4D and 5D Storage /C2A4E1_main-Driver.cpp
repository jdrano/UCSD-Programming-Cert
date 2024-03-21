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

//#define DEBUG

#include <cstdlib>
#include <iostream>
using std::cout;

#ifdef DEBUG
#include <ctime>
#endif

constexpr int MIDPOINT = RAND_MAX / 2;
constexpr int MAX_DEVIATION = int(MIDPOINT * 0.065);
constexpr int MAXIMUM = MIDPOINT + MAX_DEVIATION;
constexpr int MINIMUM = MIDPOINT - MAX_DEVIATION;

void WorkerFunction(float* nestedAvg, float* linearAvg);

int main()
{
#ifdef DEBUG
    float greatestPositiveDeviation = 0, greatestNegativeDeviation = 0;
    time_t current, previous = time(0);
#endif

    float nestedAvg = 123456e16F, linearAvg = -678421e2F;

#ifdef DEBUG
    for (;;)
    {
        while ((current = time(0)) == previous)
            ;
        previous = current;
#endif
        WorkerFunction(&nestedAvg, &linearAvg); 
        cout << "The average of all elements using nested loops is "
            << nestedAvg << '\n';
        cout << "The average of all elements using linear access is "
            << linearAvg << '\n';

#ifdef DEBUG
        if (nestedAvg > MIDPOINT)
        {
            float deviation = nestedAvg - MIDPOINT;
            if (deviation > greatestPositiveDeviation)
                greatestPositiveDeviation = deviation;
        }
        else if (nestedAvg < MIDPOINT)
        {
            float deviation = MIDPOINT - nestedAvg;
            if (deviation > greatestNegativeDeviation)
                greatestNegativeDeviation = deviation;
        }
        cout << "Allowed deviation: +-" << MAX_DEVIATION << "\n";
        cout << "Greatest Deviations: " << -greatestNegativeDeviation << "; +" <<
            greatestPositiveDeviation << "\n";
#endif

        if (nestedAvg != linearAvg)
            cout << "Failure: Averages don't match.\n";
        else
        {
            if (nestedAvg < MINIMUM || nestedAvg > MAXIMUM)
                cout << "Failure: Averages match but their values "
                "are out of the expected range.\n";
            else
                cout << "*** Averages match and their values "
                "are within the expected range.\n";
        }
#ifdef DEBUG
    }
#endif
    return EXIT_SUCCESS;
}

#endif
