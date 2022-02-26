/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <forward_list>
#include <functional>

namespace q4
{
    /**
     * Main function to test the solution below
     */
    void test();

    // Some aliases for concise code
    template <class T>
    using list_t = std::forward_list<T>;

    /**
     * Partition the given singly linked list
     */
    template <class T, class Lt = std::less<>>
    bool partition(T part, list_t<T>& list, Lt&& lt = Lt{})
    {
        using iter = typename list_t<T>::iterator;

        // Empty list; no need to do anything
        if (list.empty())
            return false;

        // Find the first node that has a value >= partition value
        const iter pivotNode = std::find_if(
            list.begin(),
            list.end(),
            [&lt, part](const T& item) { return !lt(item, part); });

        // Node with the given value not found
        if (pivotNode == list.end())
            return false;

        // Iterators to use in the next loop
        iter it = pivotNode; // base position that does not get removed
        iter next = std::next(it); // always the freshly next one
        bool moved = false; // whether a change was made

        // Go through the list, starting from the node next to the pivot node,
        // and move the ones smaller than the partition value to the front
        while (next != list.end()) {
            if (lt(*next, part))
            {
                // Found a smaller value on the right side
                list.push_front(*next);
                list.erase_after(it); // The iter `next` is invalid now
                moved = true;
            }
            else
            {
                ++it; // Move on to the next node
            }

            // Compute the fresh next node
            next = std::next(it);
        }

        return moved;
    }
}
