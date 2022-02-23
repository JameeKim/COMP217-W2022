/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <iomanip>
#include <ostream>
#include <set>
#include <utility>
#include <vector>

namespace q1
{
    /**
     * Main function to test the solution below
     */
    void test();

    /**
     * A 2d matrix with non-changeable size (and minimal input validation)
     */
    template <class Elem>
    class Matrix
    {
        template <bool Test>
        using enable_if = std::enable_if_t<Test>;

        template <class From, class To>
        constexpr static bool is_convertible = std::is_convertible_v<From, To>;

        template <class T>
        using vector2d = std::vector<std::vector<T>>;

        using streamsize = std::streamsize;

    public:
        /**
         * Implicit constructor from an initializer list
         *
         * Complexity: O(M*N)
         */
        template <
            class Row = std::initializer_list<Elem>,
            class = enable_if<is_convertible<Row, std::vector<Elem>>>>
        Matrix(std::initializer_list<Row> list)
        {
            data.reserve(list.size()); // O(c) (bc size = 0)
            for (const Row& rowList : list) // O(M)
                data.push_back(rowList); // O(c) + O(N) => O(M*N)
        }

        size_t rows() const { return data.size(); }
        size_t columns() const { return !data.empty() ? data[0].size() : 0; }
        bool isValid() const { return columns() > 0; }

        // Utility value for printing the matrix on the console
        streamsize printWidth() const { return printWidthValue; }
        void printWidth(const streamsize width) { printWidthValue = width; }

        /**
         * Get immutable element at (i, j) with bounds check
         *
         * Complexity: O(c)
         */
        const Elem& at(const size_t i, const size_t j) const
        {
            return data.at(i).at(j);
        }

        /**
         * Get mutable element at (i, j) with bounds check
         *
         * Complexity: O(c)
         */
        Elem& at(const size_t i, const size_t j)
        {
            return data.at(i).at(j);
        }

        /**
         * Fill all entries with the given value
         *
         * Complexity: O(M*N)
         */
        void fill(const Elem& val)
        {
            for (std::vector<Elem>& row : data) // O(M)
                std::fill(row.begin(), row.end(), val); // O(N)
        }

    private:
        vector2d<Elem> data;
        streamsize printWidthValue = 0;
    }; // class Matrix

    /**
     * Utility method to check existence of a value in a set
     *
     * Complexity: O(log(size))
     */
    inline bool setHas(const std::set<size_t>& set, const size_t val)
    {
        return set.find(val) != set.end();
    }

    /**
     * Answer function to the question
     *
     * Complexity: O(M*N*log(M)) or O(M*N*log(N)) => O(n*log(n)) for n = M*N
     */
    template <class T, class = std::enable_if_t<std::is_arithmetic_v<T>>>
    void applyZero(Matrix<T>& matrix)
    {
        // Let's say:
        // M = # of rows
        // N = # of columns

        // Sets of indices for rows and columns that contain zeros
        using set = std::set<size_t>;
        set zeroRows;
        set zeroColumns;

        // Collect which rows and columns have zeros
        for (size_t i = 0; i < matrix.rows(); i++) // O(M)
            for (size_t j = 0; j < matrix.columns(); j++) // O(N) => O(M*N)
                if (matrix.at(i, j) == 0)
                {
                    zeroRows.insert(i); // O(log(size)) => O(M*N*log(M))
                    zeroColumns.insert(j); // O(log(size)) => O(M*N*log(N))
                }

        // Shortcut for a case where all elements should be zero
        if (zeroRows.size() == matrix.rows()
            || zeroColumns.size() == matrix.columns())
        {
            matrix.fill(0); // O(M*N)
            return;
        }

        // Set rows and columns in the sets above to zeros
        for (size_t i = 0; i < matrix.rows(); i++) // O(M)
        {
            const bool thisRowZero = setHas(zeroRows, i); // => O(M*log(M))
            for (size_t j = 0; j < matrix.columns(); j++) // O(N) => O(M*N)
                if (thisRowZero || setHas(zeroColumns, j)) // => O(M*N*log(N))
                    matrix.at(i, j) = 0;
        }
    } // void applyZero(Matrix<T>&)
} // namespace q1

/**
 * Operator overloading for outputting Matrix to a stream
 */
template <class Elem, class Traits, class T>
std::basic_ostream<Elem, Traits>& operator<<(
    std::basic_ostream<Elem, Traits>& oStream,
    const q1::Matrix<T>& matrix)
{
    if (!matrix.isValid())
    {
        oStream << "[Invalid Matrix (" << matrix.rows() << ", "
            << matrix.columns() << ")]" << std::endl;
        return oStream;
    }

    oStream << "[Matrix (" << matrix.rows() << ", " << matrix.columns() << ")]"
        << std::endl;

    for (size_t i = 0; i < matrix.rows(); i++)
    {
        oStream << "| ";

        for (size_t j = 0; j < matrix.columns(); j++)
        {
            oStream << std::setw(matrix.printWidth()) << matrix.at(i, j);

            if (j < matrix.columns() - 1)
                oStream << " ";
        }

        oStream << " |" << std::endl;
    }

    return oStream;
}
