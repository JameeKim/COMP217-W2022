/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <set>

#include "List.h"

namespace q6
{
    /**
     * Main function to test the solution below
     */
    void test();

    /**
     * Determine if the two lists intersect, and if they do, return the pointer
     * to the intersecting node
     *
     * The consumer of this function should not try to dereference the returned
     * pointer if the second part of the returned pair is false.
     *
     * Complexity: O(n*log(n))
     */
    template <class T>
    std::pair<list::ListConstIterator<T>, bool> intersection(
        const list::List<T>& l1,
        const list::List<T>& l2)
    {
        using namespace list;

        std::set<ListConstIterator<T>, NodeAddrCmp<T>> l1Cache;

        for (auto it = l1.begin(); it != l1.end(); ++it) // O(n)
        {
            l1Cache.insert(it); // O(log(size)) => O(n*log(n))
        }

        bool found = false;

        auto it = l2.begin();
        for (; it != l2.end(); ++it) // O(n)
        {
            if (l1Cache.find(it) != l1Cache.end()) // O(log(n)) => O(n*log(n))
            {
                found = true;
                break;
            }
        }

        return std::make_pair(found ? it : ListConstIterator<T>(), found);
    }
}
