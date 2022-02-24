/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Q2Compression.h"

#include <iostream>
#include <map>
#include <vector>

#include "ConsoleUtils.h"

using namespace std;

void doTest(const char* input);

void q2::test()
{
    doTest("xkej");
    doTest("aabcccccaaa");
    doTest("ddddllieeeecnnnssss");
}

string q2::compress(const char* input)
{
    vector<pair<char, size_t>> charMap;

    const char* c = input;
    for (; *c != '\0'; c++)
    {
        if (charMap.empty() || *c != charMap.back().first)
            // new character sequence happening
            charMap.emplace_back(*c, 1);
        else
            // increment counter
            charMap.back().second++;
    }

    const size_t inputSize = c - input;
    string result;

    for (const pair<char, size_t>& p : charMap)
    {
        result += p.first;
        result += to_string(p.second);
    }

    if (result.size() >= inputSize)
        result = input;

    return result;
}

string q2::compress(const string& input)
{
    return compress(input.c_str());
}

void doTest(const char* input)
{
    using console::color;
    using console::noColor;
    namespace fmt = console::format;

    const string result = q2::compress(input);
    const WORD textColor =
        result.length() < std::strlen(input) ? fmt::green : fmt::red;

    cout << color(textColor) << input << " (" << strlen(input) << ") => "
        << result << " (" << result.size() << ")" << endl << noColor();
}
