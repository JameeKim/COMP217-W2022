/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <stdexcept>
#include <string>

namespace q3
{
    /**
     * Main function to test the solution below
     */
    void test();

    /**
     * Test if the given string is a permutation of a palindrome
     *
     * Ignores any characters that are not alphabets or digits.
     *
     * Complexity: O(n) where n = (length of input string)
     */
    bool isPalindromePermutation(const char* input);

    inline bool isPalindromePermutation(const std::string& input)
    {
        return isPalindromePermutation(input.c_str());
    }

    /**
     * Runtime exception
     */
    class PalindromePermutationError final : public std::runtime_error
    {
    public:
        explicit PalindromePermutationError(const std::string& msg)
            : runtime_error(msg) {}

        explicit PalindromePermutationError(const char* msg)
            : runtime_error(msg) {}
    };
}
