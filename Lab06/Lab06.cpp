/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <functional>
#include <iostream>

#include "ConsoleUtils.h"
#include "Q1Matrix.h"
#include "Q2Compression.h"
#include "Q3Palindrome.h"

using namespace std;

/**
 * Run the test for a question
 */
void runTest(int testNumber, const function<void()>& testFunction);

/**
 * The main application function
 */
int main(int argc, char* argv[])
{
    runTest(1, q1::test);
    runTest(2, q2::test);
    runTest(3, q3::test);
    return 0;
}

void printErr(const int testNumber, const char* type, const char* msg)
{
    cout << endl;
    cerr << type << " while running test for question #" << testNumber << endl;
    cerr << msg << endl;
}

void runTest(const int testNumber, const function<void()>& testFunction)
{
    cout << endl << console::bold() << "-------- Test Question #" << testNumber
        << " --------" << endl << console::noBold();

    try
    {
        testFunction();
    }
    catch (const std::runtime_error& error)
    {
        printErr(testNumber, "Runtime error", error.what());
    }
    catch (const std::logic_error& error)
    {
        printErr(testNumber, "Logic error", error.what());
    }
    catch (const std::exception& error)
    {
        printErr(testNumber, "Exception", error.what());
    }
    catch (...)
    {
        printErr(testNumber, "Unknown error", "Unknown failure occurred");
    }
}
