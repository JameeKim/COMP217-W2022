/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Q4Partition.h"

#include <iostream>

#include "ConsoleUtils.h"

using namespace std;
namespace fmt = console::format;

template <class T, class Lt = std::less<>>
void doTest(T part, q4::list_t<T>&& list, Lt lt = Lt{});

void q4::test()
{
    cout << "("
        << fmt::color(fmt::green) << "green" << fmt::noColor()
        << " - correct place; "
        << fmt::color(fmt::red) << "red" << fmt::noColor()
        << " - wrong place; "
        << fmt::color(fmt::blue) << "blue" << fmt::noColor()
        << " - pivot; "
        << fmt::highlight() << "emph" << fmt::noHighlight() << " - partition)"
        << endl;

    doTest(5, { 3, 5, 8, 5, 9, 2, 1 });
    doTest(3, { 9, 1, 5, 2, 8, 4, 3, 9, 0 });
    doTest(8, { 5, 2, 1, 7, 4, 3, 8, 9 });
    doTest(6, { 2, 0, 3, 1, 7, 4, 5, 9, 3, 5 });
    doTest(7, { 5, 7, 0, 2, 1, 5, 2, 8, 3, 7 });

    constexpr static char str[] = "mynameisjamee";
    doTest('j', { std::begin(str), std::end(str) - 1 });
}

/**
 * Print the list with the given partition (inserts a space before)
 */
template <class T, class Lt = std::less<>>
void printList(const T& part, const q4::list_t<T>& list, const Lt& lt)
{
    constexpr static fmt::flag colorPivot = fmt::blue;

    // Whether the iteration passed the pivot node or not
    bool afterPivot = false;

    for (const T& e : list)
    {
        cout << " ";

        if (lt(e, part))
        {
            cout << fmt::color(afterPivot ? fmt::red : fmt::green) << e
                << fmt::noColor();
        }
        else
        {
            if (e == part)
                cout << fmt::highlight();

            cout << fmt::color(afterPivot ? fmt::green : colorPivot) << e
                << fmt::noColor();

            if (e == part)
                cout << fmt::noHighlight();

            afterPivot = true;
        }
    }
}

template <class T, class Lt>
void doTest(const T part, q4::list_t<T>&& list, Lt lt)
{
    cout << "- Before:";
    printList(part, list, lt);
    cout << endl << "  After :";

    const bool changed = q4::partition(part, list, lt);

    printList(part, list, lt);

    if (!changed)
        cout << " (no change)";

    cout << endl;
}
