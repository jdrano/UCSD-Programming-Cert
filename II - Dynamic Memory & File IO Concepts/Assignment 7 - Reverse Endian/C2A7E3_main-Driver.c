#define INSTRUCTOR_FILE    // DO NOT DEFINE THIS MACRO IN ANY FILES YOU CREATE

/***  YOU DO NOT NEED TO UNDERSTAND THE CODE IN THIS FILE TO WRITE YOURS  ***/

/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/
/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/
/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/

///****************************************************************************
// Everything in this file was written to help test/verify your code and must
// not be altered in any way.  Do not rename this file or copy anything from
// it into your file(s).  This file does not necessarily represent good coding
// technique, proper formatting/style, or meet the requirements your code must
// meet.  You do not need to understand the code in this file to write yours.
///****************************************************************************
#ifdef INSTRUCTOR_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TestIt(a, b, type) (TestReverse((void *)&(a),\
   ReverseEndian((void *)&(b), sizeof(b)), sizeof(b), (type)))

void* ReverseEndian(void* ptr, size_t size);
static void TestReverse(const void* before, const void* after, size_t size,
    const char* type);

int main(void)
{
    // Some objects to test...
    char ch = 0x01, ch1;
    short sh = 0x0123, sh1;
    long lo = 0x01234567, lo1;
    float fl = 1234.567e27F, fl1;
    double db = 123456.567890, db1;
    void* vp = (void*)0x0123, * vp1;
    char* cp = (char*)0x4567, * cp1;
    char* ip = (char*)0x89AB, * ip1;

    memcpy(&ch1, &ch, sizeof(ch1));
    memcpy(&sh1, &sh, sizeof(sh1));
    memcpy(&lo1, &lo, sizeof(lo1));
    memcpy(&fl1, &fl, sizeof(fl1));
    memcpy(&db1, &db, sizeof(db1));
    memcpy(&vp1, &vp, sizeof(vp1));
    memcpy(&cp1, &cp, sizeof(cp1));
    memcpy(&ip1, &ip, sizeof(ip1));

    TestIt(ch1, ch, "char");
    TestIt(sh1, sh, "short");
    TestIt(lo1, lo, "long");
    TestIt(fl1, fl, "float");
    TestIt(db1, db, "double");
    TestIt(vp1, vp, "void pointer");
    TestIt(cp1, cp, "char pointer");
    TestIt(ip1, ip, "int pointer");

    return EXIT_SUCCESS;
}

void TestReverse(const void* before, const void* after, size_t size,
    const char* type)
{
    const char* cpBfore = (const char*)before;
    const char* cpAfter = (const char*)after;
    const char* tail;

    for (tail = cpBfore + (size - 1); size; --size)
        if (*tail-- != *cpAfter++)
        {
            fprintf(stderr, "ReverseEndian FAILED for type \"%s\"\n", type);
            return;
        }
    printf("ReverseEndian succeeded for type \"%s\"\n", type);
}
#endif
