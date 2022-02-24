/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <ostream>
#include <stdexcept>
#include <Windows.h>

/**
 * Utilities for manipulating windows console output
 */
namespace console
{
    /**
     * Runtime exception
     */
    class ConsoleUtilsError final : public std::runtime_error
    {
    public:
        explicit ConsoleUtilsError(const std::string& msg)
            : runtime_error(msg) {}

        explicit ConsoleUtilsError(const char* msg) : runtime_error(msg) {}
    };

    /**
     * Helper for setting text formats
     */
    namespace format
    {
        // ReSharper disable CppInconsistentNaming

        constexpr WORD red = FOREGROUND_RED;
        constexpr WORD blue = FOREGROUND_BLUE;
        constexpr WORD green = FOREGROUND_GREEN;
        constexpr WORD white = red | blue | green;
        constexpr WORD strong = FOREGROUND_INTENSITY;
        constexpr WORD fg = white | strong;

        constexpr WORD bg_red = BACKGROUND_RED;
        constexpr WORD bg_blue = BACKGROUND_BLUE;
        constexpr WORD bg_green = BACKGROUND_GREEN;
        constexpr WORD bg_white = bg_red | bg_blue | bg_green;
        constexpr WORD bg_strong = BACKGROUND_INTENSITY;
        constexpr WORD bg = bg_white | bg_strong;

        constexpr WORD highlight = COMMON_LVB_REVERSE_VIDEO;
        // constexpr WORD underline = COMMON_LVB_UNDERSCORE; // doesn't work
        constexpr WORD style_mask = highlight;

        constexpr WORD all = fg | bg | style_mask;
        constexpr WORD none = 0x0000;
        constexpr WORD pass = ~none;

        // ReSharper restore CppInconsistentNaming
    }

    // Type alias for concise code
    template <class Elem, class Traits>
    using os = std::basic_ostream<Elem, Traits>;

    /**
     * IO manipulator for windows console colors
     */
    class TextFormatter
    {
    public:
        explicit TextFormatter(const WORD attrs, const WORD mask)
            : attrs(attrs & mask), mask(mask) {}

        template <class C, class CT>
        friend os<C, CT>& operator<<(os<C, CT>& os, const TextFormatter& fmt);

    private:
        WORD attrs;
        WORD mask;
    };

    /**
     * Helper function to intensify the foreground color
     */
    inline TextFormatter bold()
    {
        return TextFormatter(format::strong, format::strong);
    }

    /**
     * Helper function to reset bold
     */
    inline TextFormatter noBold()
    {
        return TextFormatter(format::none, format::strong);
    }

    /**
     * Helper function to set the color of the text
     */
    inline TextFormatter color(const WORD c)
    {
        return TextFormatter(c, format::white);
    }

    /**
     * Helper function to revert the color of the text (to white)
     */
    inline TextFormatter noColor()
    {
        return color(format::white);
    }

    /**
     * Get current text attributes
     */
    WORD getCurrentTextAttributes();

    /**
     * Set text attributes
     */
    void setTextAttributes(WORD attrs);

    /**
     * Operator overloading for changing windows console colors
     */
    template <class C, class CT>
    os<C, CT>& operator<<(os<C, CT>& os, const TextFormatter& fmt)
    {
        const WORD flags = ~fmt.mask & getCurrentTextAttributes() | fmt.attrs;
        setTextAttributes(flags);
        return os;
    }
}
