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

#include <fstream>
#include <iostream>
using namespace std;

const char* const TEST_APPEND_EXPECTED_RESULTS_FILE_NAME =
"Append_ExpectedResults.bin";
const char* const TEST_APPEND_TARGET_FILE_NAME = "Append_ActualResults.out";
const char* const TEST_INFILE1_NAME = "Append_GettysburgAddress.txt";
const char* const TEST_INFILE2_NAME = "Append_3000Nulls.bin";

int AppendFile(const char* inFile, const char* outFile);

//
// Test: AppendFile
//
int main()
{
    int tests = 0, errors = 0;

    ifstream ifStmActual, ifStmExpected;

    remove(TEST_APPEND_TARGET_FILE_NAME);
    AppendFile(TEST_INFILE1_NAME, TEST_APPEND_TARGET_FILE_NAME);
    AppendFile(TEST_INFILE2_NAME, TEST_APPEND_TARGET_FILE_NAME);
    AppendFile(TEST_INFILE1_NAME, TEST_APPEND_TARGET_FILE_NAME);
    AppendFile(TEST_INFILE2_NAME, TEST_APPEND_TARGET_FILE_NAME);

    ++tests;
    ifStmActual.open(TEST_APPEND_TARGET_FILE_NAME, ios_base::binary);
    if (!ifStmActual.is_open())
    {
        ++errors;
        cerr << "File open failure: \"" << TEST_APPEND_TARGET_FILE_NAME <<
            "\".\n\n";
    }
    else
    {
        ifStmExpected.open(TEST_APPEND_EXPECTED_RESULTS_FILE_NAME,
            ios_base::binary);
        if (!ifStmExpected.is_open())
        {
            ++errors;
            cerr << "File open failure: \"" <<
                TEST_APPEND_EXPECTED_RESULTS_FILE_NAME << "\".\n\n";
            ifStmActual.close();
        }
        else
        {
            ++tests;
            for (;;)
            {
                int actualCh = ifStmActual.get();
                int expectedCh = ifStmExpected.get();
                if (actualCh == expectedCh)
                {
                    if (actualCh == EOF)
                        break;
                }
                else
                {
                    cerr << "***ERROR*** AppendFile: Concatenation failed.\n";
                    ++errors;
                    break;
                }
            }
        }
    }

    const char* plural = errors != 1 ? "s" : "";
    if (errors)
        cerr << '\n';
    cerr << "C2A1E6: " << tests << " tests " << errors << " error"
        << plural << ".\n\n";

    return 0;
}
#endif
