/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Q3Palindrome.h"

#include <cctype>
#include <iostream>
#include <map>

#include "ConsoleUtils.h"

void doTest(bool expected, const char* input);

void q3::test()
{
    constexpr std::pair<bool, const char*> params[] = {
        { true , "Race car!" },
        { false, " .@#& -[,]" },
        { false, "Cats are cute :)" },
        { false, "The quick brown fox jumps over the lazy dog." },
        { true, "Cat & Taco" },
    };

    for (const auto& p : params)
        doTest(p.first, p.second);
}

/**
 * Type alias for C type characters
 */
// ReSharper disable once IdentifierTypo
using uchar = unsigned char;

/**
 * Conversion to unsigned char for using NTBS (null-terminated byte string)
 * library (e.g., isalnum, isupper, tolower, ...)
 *
 * See https://en.cppreference.com/w/cpp/string/byte/isalnum
 */
template <class T>
uchar toUChar(const T c) { return static_cast<uchar>(c); }

bool q3::isPalindromePermutation(const char* input)
{
    std::map<uchar, size_t> charMap;

    // Collect data on the input string
    for (const char* ch = input; *ch != '\0'; ch++) // O(n)
    {
        uchar c = toUChar(*ch);

        // Ignore any whitespaces or punctuations (This actually also just skips
        // any control characters, but I won't care about it for now)
        if (!std::isalnum(c))
            continue;

        // Force to lowercase letters
        if (std::isupper(c))
            c = toUChar(std::tolower(c));

        // Increase counts
        charMap[c]++; // O(log(size)) => O(n*log(n))
    }

    // String is empty of meaningful characters
    if (charMap.empty())
        return false;

    // Number of chars that appeared odd number of times
    size_t oddCount = 0;

    // 1. Even number of letters means even number of appearance for all letters
    // 2. With odd number of letters, there should be one and only one letter
    //    that appears odd number of times
    // => Combined, oddCount should be either 0 or 1 (no larger than 1)
    // (We don't have to manually check if the total count is even or not
    // because the value of oddCount being 0 or 1 naturally follows whether the
    // total count is even or odd)
    for (const auto& pair : charMap) // O(n)
    {
        if (pair.second % 2 == 1)
            oddCount++;

        // Early exit since we already know it doesn't satisfy
        if (oddCount > 1)
            return false;
    }

    // All tests passed
    return true;
} // bool q3::isPalindromePermutation(const char*)

// Just some texts to use when displaying
const char* correct = " Correct ";
const char* incorrect = "Incorrect";
const char* is = "is";
const char* isNot = "is not";

void doTest(const bool expected, const char* input)
{
    using console::color;
    using console::noColor;
    using console::bold;
    using console::noBold;
    namespace fmt = console::format;

    const bool result = q3::isPalindromePermutation(input);
    const bool isCorrect = result == expected;

    std::cout << color(isCorrect ? fmt::green : fmt::red) << bold()
        << "[" << (isCorrect ? correct : incorrect) << "] " << noBold()
        << noColor() << '"' << input << "\" " << bold() << (result ? is : isNot)
        << noBold() << " a permutation of a palindrome" << std::endl;
}
