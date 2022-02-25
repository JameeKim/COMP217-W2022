/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Q3Palindrome.h"

#include <cctype>
#include <iostream>
#include <locale>
#include <map>

#include "ConsoleUtils.h"

using namespace q3;

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
 *
 * This is needed for using NTBS (null-terminated byte string) library
 * (e.g., isalnum, isupper, tolower, ...)
 *
 * See https://en.cppreference.com/w/cpp/string/byte/isalnum
 */
// ReSharper disable once IdentifierTypo
using uchar = unsigned char;

namespace chars
{
    /**
     * Bit flags for characters we're tracking (alpha-numerics) (ull; 64 bits)
     *
     * We're using this because ul (32 bits) cannot store all of /[a-z0-9]/
     * which requires 36 bits.
     *
     * More explanation on why I'm doing this below in the actual function.
     */
    using char_flag = unsigned long long;

    /**
     * Visualization for the bit flags
     */
    // ReSharper disable once CppInconsistentNaming
    enum chars : char_flag
    {
        invalid = 0x0000'0000'0000'0000, // not alpha-numeric
        // ---------------------------------------------------------------------
        a       = 0x0000'0000'0000'0001, // 'a' (1 << 0)
        b       = 0x0000'0000'0000'0002, // 'b' (1 << 1)
        c       = 0x0000'0000'0000'0004, // 'c' (1 << 2)
        d       = 0x0000'0000'0000'0008, // 'd' (1 << 3)
        e       = 0x0000'0000'0000'0010, // 'e' (1 << 4)
        f       = 0x0000'0000'0000'0020, // 'f' (1 << 5)
        g       = 0x0000'0000'0000'0040, // 'g' (1 << 6)
        h       = 0x0000'0000'0000'0080, // 'h' (1 << 7)
        i       = 0x0000'0000'0000'0100, // 'i' (1 << 8)
        j       = 0x0000'0000'0000'0200, // 'j' (1 << 9)
        k       = 0x0000'0000'0000'0400, // 'k' (1 << 10)
        l       = 0x0000'0000'0000'0800, // 'l' (1 << 11)
        m       = 0x0000'0000'0000'1000, // 'm' (1 << 12)
        n       = 0x0000'0000'0000'2000, // 'n' (1 << 13)
        o       = 0x0000'0000'0000'4000, // 'o' (1 << 14)
        p       = 0x0000'0000'0000'8000, // 'p' (1 << 15)
        q       = 0x0000'0000'0001'0000, // 'q' (1 << 16)
        r       = 0x0000'0000'0002'0000, // 'r' (1 << 17)
        s       = 0x0000'0000'0004'0000, // 's' (1 << 18)
        t       = 0x0000'0000'0008'0000, // 't' (1 << 19)
        u       = 0x0000'0000'0010'0000, // 'u' (1 << 20)
        v       = 0x0000'0000'0020'0000, // 'v' (1 << 21)
        w       = 0x0000'0000'0040'0000, // 'w' (1 << 22)
        x       = 0x0000'0000'0080'0000, // 'x' (1 << 23)
        y       = 0x0000'0000'0100'0000, // 'y' (1 << 24)
        z       = 0x0000'0000'0200'0000, // 'z' (1 << 25)
        // ---------------------------------------------------------------------
        zero    = 0x0000'0000'0400'0000, // '0' (1 << 26)
        one     = 0x0000'0000'0800'0000, // '1' (1 << 27)
        two     = 0x0000'0000'1000'0000, // '2' (1 << 28)
        three   = 0x0000'0000'2000'0000, // '3' (1 << 29)
        four    = 0x0000'0000'4000'0000, // '4' (1 << 30)
        five    = 0x0000'0000'8000'0000, // '5' (1 << 31)
        six     = 0x0000'0001'0000'0000, // '6' (1 << 32)
        seven   = 0x0000'0002'0000'0000, // '7' (1 << 33)
        eight   = 0x0000'0004'0000'0000, // '8' (1 << 34)
        nine    = 0x0000'0008'0000'0000, // '9' (1 << 35)
        // ---------------------------------------------------------------------
        alpha   = 0x0000'0000'03FF'FFFF, // alphabets
        digit   = 0x0000'000F'FC00'0000, // digits
        all     = 0x0000'000F'FFFF'FFFF, // all alpha-numerics
    };

    /**
     * Compute the bit field for the given character
     */
    inline char_flag flag(const uchar c)
    {
        // Ignore any whitespaces or punctuations (This actually also just skips
        // any control characters, but I won't care about it for now)
        if (!std::isalnum(c))
            return invalid;

        // A digit character
        if (std::isdigit(c))
            return 1ull << (c - '0' + 26);

        // An alphabet character (case-insensitive)
        return 1ull << (c - (std::islower(c) ? 'a' : 'A'));
    }

    /**
     * Toggle the given field of the flags (0 -> 1, 1 -> 0)
     */
    inline void toggle(char_flag& flags, const char_flag field)
    {
        if (flags & field)
            // The field is already set; set the field to 0
            flags &= ~field;
        else
            // The field is not set; set the field to 1
            flags |= field;
    }
}

bool q3::isPalindromePermutation(const char* input)
{
    // For the input string to be a permutation of a palindrome,
    // 1. even number of letters means even number of appearance for all letters
    // 2. with odd number of letters, there should be one and only one letter
    //    that appears odd number of times
    // => Combined, there should be at most 1 character that appears odd number
    //    of times in the string.
    // (We don't have to manually check if the total count is even or not
    // because the value of oddCount being 0 or 1 naturally follows whether the
    // total count is even or odd)
    // => Using the bit fields for alpha-numeric characters, we track if each
    //    character appears in the input string even number of times or odd
    //    number of times. This way, we don't need another data structure like
    //    std::map (O(log(n))) or std::unordered_map (O(n)).

    using chars::char_flag;

    // Track even/odd for each character (0 for even, 1 for odd)
    char_flag charCounts = 0;

    // For checking if the string actually had any meaningful characters
    bool hasAlphaNum = false;

    // Collect data on the input string
    for (const char* c = input; *c != '\0'; c++) // O(n)
    {
        const char_flag cFlag = chars::flag(static_cast<uchar>(*c));

        // Skip non-alpha-numeric characters
        if (cFlag == chars::invalid)
            continue;

        chars::toggle(charCounts, cFlag); // Toggle even/odd
        hasAlphaNum = true; // Mark the existence
    }
    // All operations O(c) => O(n) in total due to the for loop

    // No alpha-numeric characters => I wouldn't say it's a palindrome
    if (!hasAlphaNum)
        return false;

    // All characters appeared even number of times => case (1)
    if (charCounts == 0)
        return true;

    // Only 1 character appeared odd number of times => case (2)
    if ((charCounts & (charCounts - 1)) == 0)
        return true;

    // All tests failed
    return false;
} // bool isPalindromePermutation(const char*)

// Just some texts to use when displaying
const char* correct = " Correct ";
const char* incorrect = "Incorrect";
const char* is = "is";
const char* isNot = "is not";

void doTest(const bool expected, const char* input)
{
    namespace fmt = console::format;

    const bool result = isPalindromePermutation(input);
    const bool isCorrect = result == expected;

    std::cout << fmt::color(isCorrect ? fmt::green : fmt::red) << fmt::bold()
        << "[" << (isCorrect ? correct : incorrect) << "] " << fmt::noBold()
        << fmt::noColor() << '"' << input << "\" " << fmt::bold()
        << (result ? is : isNot) << fmt::noBold()
        << " a permutation of a palindrome" << std::endl;
}
