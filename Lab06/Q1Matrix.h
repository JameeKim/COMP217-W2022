/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <array>
#include <iomanip>
#include <ostream>
#include <set>
#include <type_traits>
#include <utility>

#include "ConsoleUtils.h"

namespace q1
{
    /**
     * Main function to test the solution below
     */
    void test();

    // Some aliases for concise code
    template <bool Test>
    using require = std::enable_if_t<Test>;
    template <class From, class To>
    constexpr bool is_convertible = std::is_convertible_v<From, To>;
    template <class T>
    constexpr bool is_number = std::is_arithmetic_v<T>;
    using std::array;
    template <class T>
    using init_list = std::initializer_list<T>;
    using stream_size = std::streamsize;
    template <class C, class CT>
    using os = std::basic_ostream<C, CT>;

    /**
     * A 2d matrix with non-changeable size
     */
    template <class T, size_t M, size_t N>
    class Matrix
    {
    public:
        // Type aliases
        using row_t = array<T, N>;
        using data_t = array<row_t, M>;
        using iterator = typename data_t::iterator;
        using const_iterator = typename data_t::const_iterator;

        /**
         * Implicit constructor from an initializer list
         *
         * Complexity: O(M*N) => O(n) for n = M*N
         */
        Matrix(init_list<init_list<T>> list)
        {
            size_t rowIdx = 0;

            for (const init_list<T>& row : list)
                std::copy(row.begin(), row.end(), inner[rowIdx++].begin());
        }

        // Utilities for matrix size
        constexpr size_t rows() const noexcept { return M; }
        constexpr size_t cols() const noexcept { return N; }
        constexpr size_t size() const noexcept { return rows() * cols(); }
        constexpr bool empty() const noexcept { return size() == 0; }

        // Utility value for printing the matrix on the console
        stream_size printWidth() const { return printWidthValue; }
        void printWidth(const stream_size width) { printWidthValue = width; }

        // Iterator (front)
        iterator begin() noexcept { return inner.begin(); }
        const_iterator begin() const noexcept { return inner.begin(); }
        const_iterator cbegin() const noexcept { return inner.cbegin(); }

        // Iterator (back)
        iterator end() noexcept { return inner.end(); }
        const_iterator end() const noexcept { return inner.end(); }
        const_iterator cend() const noexcept { return inner.cend(); }

        // Get element at (i, j) with bounds check
        // Complexity: O(c)
        T& at(size_t i, size_t j) { return inner.at(i).at(j); }
        const T& at(size_t i, size_t j) const { return inner.at(i).at(j); }

        // Get element at (i, j) without bounds check
        // Complexity: O(c)
        row_t& operator[](size_t i) noexcept { return inner[i]; }
        const row_t& operator[](size_t i) const noexcept { return inner[i]; }

        /**
         * Fill all entries with the given value
         *
         * Complexity: O(M*N) => O(n) for n = M*N
         */
        void fill(const T& val)
        {
            for (row_t& row : inner)
                row.fill(val);
        }

    private:
        data_t inner;
        stream_size printWidthValue = 0;
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
    template <class T, size_t M, size_t N, class = require<is_number<T>>>
    void applyZero(Matrix<T, M, N>& matrix)
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
            for (size_t j = 0; j < matrix.cols(); j++) // O(N) => O(M*N)
                if (matrix.at(i, j) == 0)
                {
                    zeroRows.insert(i); // O(log(size)) => O(M*N*log(M))
                    zeroColumns.insert(j); // O(log(size)) => O(M*N*log(N))
                }

        // Shortcut for a case where all elements should be zero
        if (zeroRows.size() == matrix.rows()
            || zeroColumns.size() == matrix.cols())
        {
            matrix.fill(0); // O(M*N)
            return;
        }

        // Set rows and columns in the sets above to zeros
        for (size_t i = 0; i < matrix.rows(); i++) // O(M)
        {
            const bool thisRowZero = setHas(zeroRows, i); // => O(M*log(M))
            for (size_t j = 0; j < matrix.cols(); j++) // O(N) => O(M*N)
                if (thisRowZero || setHas(zeroColumns, j)) // => O(M*N*log(N))
                    matrix.at(i, j) = 0;
        }
    } // void applyZero(Matrix&)

    /**
     * Operator overloading for outputting Matrix to a stream
     */
    template <
        class T, size_t M, size_t N, // Matrix
        class C, class CT, // os
        class = require<is_number<T>>>
    os<C, CT>& operator<<(os<C, CT>& oStream, const Matrix<T, M, N>& matrix)
    {
        if (matrix.empty())
        {
            oStream << "[Invalid Matrix (" << matrix.rows() << ", "
                << matrix.cols() << ")]" << std::endl;
            return oStream;
        }

        oStream << "[Matrix (" << matrix.rows() << ", " << matrix.cols()
            << ")]" << std::endl;

        for (const typename Matrix<T, M, N>::row_t& row : matrix)
        {
            oStream << "| ";

            for (const T& elem : row)
            {
                if (elem == 0)
                    oStream << console::format::bold();

                oStream << std::setw(matrix.printWidth()) << elem
                    << console::format::noBold() << " ";
            }

            oStream << "|" << std::endl;
        }

        return oStream;
    } // os& operator<<(os&, const Matrix&)
} // namespace q1
