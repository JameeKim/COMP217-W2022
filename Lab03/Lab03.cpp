/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #3 (due Sun. Feb. 06, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>
#include <vector>

using namespace std;

int smallestElement(const int array[], const size_t size) {
    // array empty; throw an exception
    if (size == 0u)
    {
        throw "The array size must be 1 or larger";
    }

    // base case (n = 1)
    if (size == 1u)
    {
        return array[0];
    }

    // divide the array into 2 parts and do recursive computation
    const size_t half = size / 2u;
    const int front = smallestElement(array, half);
    const int end = smallestElement(array + half, size - half);
    return front < end ? front : end;
}

int findMinVector(const vector<int>& arr)
{
    const vector<int>::size_type size = arr.size();

    if (size == 0)
    {
        throw "The array must not be empty";
    }

    if (size == 1)
    {
        return arr[0];
    }

    const vector<int>::size_type half = size / 2;
    vector<int> front_vector = vector<int>();
    vector<int> end_vector = vector<int>();

    for (int i = 0; i < size; ++i)
    {
        if (i < half)
        {
            front_vector.push_back(arr[i]);
        }
        else
        {
            end_vector.push_back(arr[i]);
        }
    }

    const int front = findMinVector(front_vector);
    const int back = findMinVector(end_vector);
    return front < back ? front : back;
}

int findMin(const int arr[], const size_t length)
{
    if (length == 0)
    {
        throw "The array must not be empty";
    }

    if (length == 1)
    {
        return arr[0];
    }

    const size_t half = length / 2;
    const int front = findMin(arr, half);
    const int end = findMin(arr + half, length - half);
    return front < end ? front : end;
}

int main()
{
    constexpr int arr[] = { 4, 2, -8, 2, 9, 1, 0, -4, 6 };
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
