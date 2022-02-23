/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>

#include "Q1Matrix.h"
#include "Q2Compression.h"

using namespace std;

/**
 * Run the test for a question
 */
void runTest(int testNumber, void (*testFunction)());

/**
 * The main application function
 */
int main(int argc, char* argv[])
{
    runTest(1, q1::test);
    runTest(2, q2::test);
    return 0;
}

void printErr(const int testNumber, const char* msg)
{
    cerr << "Error while running test for question #" << testNumber << endl;
    cerr << msg << endl;
}

void runTest(const int testNumber, void (*testFunction)())
{
    cout << endl;
    cout << "------ Test Question #" << testNumber << " ------" << endl;

    try
    {
        testFunction();
    }
    catch (const char* msg)
    {
        printErr(testNumber, msg);
    }
    catch (const std::runtime_error& error)
    {
        printErr(testNumber, error.what());
    }
    catch (const std::exception& error)
    {
        printErr(testNumber, error.what());
    }
    catch (...)
    {
        printErr(testNumber, "Unknown failure occurred");
    }
}
