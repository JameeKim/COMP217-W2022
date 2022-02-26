/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Q5Duplicates.h"

#include <iostream>
#include <unordered_map>

#include "ConsoleUtils.h"

using std::cout;
using std::endl;
namespace fmt = console::format;

template <class T>
void doTest(q5::list_t<T>&& list);

void q5::test()
{
    cout << "("
        << fmt::color(fmt::blue) << "blue" << fmt::noColor()
        << " - first of the duplicates; "
        << fmt::color(fmt::red) << "red" << fmt::noColor()
        << " - duplicates needing removal)"
        << endl;

    doTest<int>({ 2, 4, 9, 2, 1, 0, 6, 2, 9, 8 });
    doTest<int>({ 1, 1, 1, 1, 1, 0, 2, 2, 2, 0, 0, 1, 2 });

    const static std::string strs[] = {
        "c++ programming",
        "Ehhhh what should I write here",
        "incomprehensibilities", // longest common word
        "uncopyrightable", // long (not longest) word without repeating letters
    };

    for (auto str = std::begin(strs); str != std::end(strs); ++str)
        doTest<char>({ std::begin(*str), std::end(*str) });
}

/**
 * Print the list and mark duplicate elements (prints a space at the start)
 *
 * This traverses through the list twice
 */
template <class T>
void printList(const q5::list_t<T>& list)
{
    std::unordered_map<T, size_t> counts;

    for (const T& e : list)
    {
        ++counts[e];
    }

    std::unordered_set<T> dups;

    for (const T& e : list)
    {
        cout << " ";

        if (counts[e] > 1)
            // duplicate element
            cout << fmt::color(dups.insert(e).second ? fmt::blue : fmt::red);

        cout << e << fmt::noColor();
    }
}

template <class T>
void doTest(q5::list_t<T>&& list)
{
    cout << "- Before:";
    printList(list);
    cout << endl << "  After :";
    const bool removed = q5::removeDuplicates(list);
    printList(list);
    if (!removed)
        cout << " (no changes)";
    cout << endl;
}
