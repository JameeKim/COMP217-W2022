/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Q1Matrix.h"

#include <iostream>

using namespace std;

void doTest(q1::Matrix<int>&& matrix);

void q1::test()
{
    doTest({
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 },
    });
    doTest({
        { 0, 9, -2, 2 },
        { -5, 0, 7, -9 },
        { 1, 4, 0, 5 },
    });
    doTest({
        { -2, 8 },
        { 7, -4 },
    });
}

void doTest(q1::Matrix<int>&& matrix)
{
    matrix.printWidth(2);
    cout << "Before:" << endl << matrix;
    applyZero(matrix);
    cout << "After:" << endl << matrix;
}
