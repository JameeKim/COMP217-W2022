/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Mid-Term Exam (Wed. Mar. 2, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <set>

namespace Subset
{
    /**
     * A type alias for the set we're going to use
     */
    using Set = std::set<int>;

    std::forward_list<Set> rec(const Set& set, const Set::const_iterator& it)
    {
        if (it == set.end())
        {
            return {};
        }

        auto next = rec(set, std::next(it));
        if (next.empty())
        {
            return { {}, { *it } };
        }

        for (auto i = next.begin(); i != next.end(); ++i, ++i)
        {
            Set added = *i;
            added.insert(*it);
            next.insert_after(i, std::move(added));
        }

        return next;
    }

    /**
     * Get a list of all subsets of the given set
     */
    std::forward_list<Set> getAllSubsets(const Set& set)
    {
        if (set.empty())
        {
            return { {} };
        }

        if (set.size() == 1)
        {
            return { {}, { *set.begin() } };
        }

        return rec(set, set.begin());
    }

    void print(const std::forward_list<Set>& list)
    {
        for (const Set& s : list)
        {
            std::cout << "{";
            for (const int& e : s) std::cout << " " << e;
            std::cout << " }" << std::endl;
        }
    }
}
