/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Q6Intersection.h"

#include <iomanip>
#include <iostream>

#include "ConsoleUtils.h"
#include "List.h"

using std::cout;
using std::endl;

template <class T>
void doTest(const list::List<T>& l1, const list::List<T>& l2);

void q6::test()
{
    using namespace list;

    cout << "Case 1: ";

    node_ptr<int> n = Node<int>::make(3);
    for (const int& i : { 2, 1 })
        n = Node<int>::make(i, n);
    List<int> l1(n), l2(n);
    for (const int& i : { 3, 2, 1 })
        l1.push(i);
    for (const int& i : { 1, 2, 3 })
        l2.push(i);
    doTest(l1, l2);

    cout << "Case 2: ";

    cout << std::fixed << std::setprecision(1);
    const List<double> l3 = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    const List<double> l4 = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    doTest(l3, l4);
    cout << std::defaultfloat << std::setprecision(0);
}

template <class T>
void printNodes(
    const list::ListConstIterator<T>& it1,
    const list::ListConstIterator<T>& it2)
{
    namespace fmt = console::format;

    if (it1 == it2)
        cout << fmt::color(fmt::green);

    cout << std::addressof(*it1.getNode()) << "(" << *it1 << ")";
    cout << (it1 == it2 ? " == " : " != ");
    cout << std::addressof(*it2.getNode()) << "(" << *it2 << ")";

    if (it1 == it2)
        cout << fmt::noColor();
}

template <class T>
void doTest(const list::List<T>& l1, const list::List<T>& l2)
{
    // Only prints properly with 2 lists with same width

    const auto res = q6::intersection(l1, l2);

    if (res.second)
        cout << "Intersection exists" << endl;
    else
        cout << "Intersection does not exist" << endl;

    auto i1 = l1.begin(), i2 = l2.begin();
    for (; i1 != l1.end(); ++i1, ++i2)
    {
        printNodes(i1, i2);
        cout << endl;
    }
}
