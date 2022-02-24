/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */


#include "Q1Matrix.h"

#include <iomanip>
#include <ios>
#include <iostream>

using namespace std;

/**
 * Run the answer function with the given matrix
 */
template <class T, size_t M, size_t N>
void doTest(
    q1::stream_size printWidth,
    q1::Matrix<T, M, N>&& matrix)
{
    matrix.printWidth(printWidth);
    cout << "Before:" << endl << matrix;
    applyZero(matrix);
    cout << "After:" << endl << matrix;
}

void q1::test()
{
    // Set the format of floating point numbers when printing to console
    cout << fixed << setprecision(1);

    // Run the tests
    doTest<int, 5, 5>(2, {
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 },
    });
    doTest<float, 3, 4>(4, {
        {  0.0f,  9.2f, -0.8f,  2.5f },
        { -5.1f,  0.0f,  7.9f, -9.3f },
        {  1.1f,  4.6f,  0.0f,  5.7f },
    });
    doTest<int, 2, 2>(2, {
        { -2,  8 },
        {  7, -4 },
    });

    cout << defaultfloat << setprecision(0);
}
