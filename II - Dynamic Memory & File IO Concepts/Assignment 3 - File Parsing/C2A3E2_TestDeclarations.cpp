//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 01/18/24
// C2A3E2_TestDeclarations.cpp
// Win10
// Visual Studio 2022
//
// This file contains practice for the reverse right left syntax rule.
//

const int Q1_PTR_SIZE = 6;

void TestDeclarations()
{
    void *(*aryP)[Q1_PTR_SIZE] = 0; //1.
    char *fcnA(void *p1);           //2.
    int(*ppa)();                    //3.
    int(*&rppa)() = ppa;            //4.
    ppa = (int(*)())aryP;           //5.
}