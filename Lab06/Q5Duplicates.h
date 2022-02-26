/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <forward_list>
#include <unordered_set>

namespace q5
{
    /**
     * Main function to test the solution below
     */
    void test();

    // Some aliases for concise code
    template <class T>
    using list_t = std::forward_list<T>;

    /**
     * Remove duplicates from from the list (unsorted)
     */
    template <class T>
    bool removeDuplicates(list_t<T>& list)
    {
        using iter = typename list_t<T>::iterator;

        bool removed = false;
        std::unordered_set<T> elements;

        iter it = list.before_begin();
        iter next = ++iter(it);

        while (next != list.end())
        {
            if (elements.insert(*next).second) // whether it's a new element
            {
                // new element found; move on to the next node
                ++it;
            }
            else
            {
                // duplicate found; remove it
                list.erase_after(it); // iterator `next` invalidated here
                removed = true;
            }

            // Get a fresh pointer to the next element
            next = ++iter(it);
        }

        return removed;
    }
}
