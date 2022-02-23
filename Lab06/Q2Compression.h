/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <string>

namespace q2
{
    /**
     * Main function to test the solution below
     */
    void test();

    /**
     * Compress the input string by counting consecutive letters
     */
    std::string compress(const char * input);
    std::string compress(const std::string& input);
}
