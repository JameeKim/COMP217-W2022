/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #3 (due Sun. Feb. 06, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>

int smallestElement(int* const arr, const int size, const int start = 0)
{
    if (size < 1)
    {
        throw "The array size must be 1 or larger";
    }

    if (start < 0)
    {
        throw "The start index must be non-negative";
    }

    if (size == 1)
    {
        return arr[start];
    }

    const int half = size / 2;
    const int front = smallestElement(arr, half, start);
    const int end = smallestElement(arr, size - half, start + half);
    return front < end ? front : end;
}

int main(int argc, char* argv[])
{
    int arr[] = { 4, 2, -8, 2, 9, 1, 0, -4, 6 };
    try
    {
        std::cout << smallestElement(arr, 9) << std::endl;
    }
    catch (const char* msg)
    {
        std::cout << "Error: " << msg << std::endl;
    }
    return 0;
}
