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
     * Type alias for text format attribute flags
     */
    using flag = WORD;

    /**
     * Helper for setting text formats
     */
    namespace format
    {
        // ReSharper disable CppInconsistentNaming

        constexpr flag red = FOREGROUND_RED;
        constexpr flag blue = FOREGROUND_BLUE;
        constexpr flag green = FOREGROUND_GREEN;
        constexpr flag white = red | blue | green;
        constexpr flag strong = FOREGROUND_INTENSITY;
        constexpr flag fg = white | strong;

        constexpr flag bg_red = BACKGROUND_RED;
        constexpr flag bg_blue = BACKGROUND_BLUE;
        constexpr flag bg_green = BACKGROUND_GREEN;
        constexpr flag bg_white = bg_red | bg_blue | bg_green;
        constexpr flag bg_strong = BACKGROUND_INTENSITY;
        constexpr flag bg = bg_white | bg_strong;

        constexpr flag highlight = COMMON_LVB_REVERSE_VIDEO;
        // constexpr flag underline = COMMON_LVB_UNDERSCORE; // doesn't work
        constexpr flag style_mask = highlight;

        constexpr flag all = fg | bg | style_mask;
        constexpr flag none = 0x0000;
        constexpr flag pass = ~none;

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
        explicit TextFormatter(const flag attrs, const flag mask)
            : attrs(attrs & mask), mask(mask) {}

        template <class C, class CT>
        friend os<C, CT>& operator<<(os<C, CT>& os, const TextFormatter& fmt);

    private:
        flag attrs;
        flag mask;
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
    inline TextFormatter color(const flag c)
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
    flag getCurrentTextAttributes();

    /**
     * Set text attributes
     */
    void setTextAttributes(flag attrs);

    /**
     * Operator overloading for changing windows console colors
     */
    template <class C, class CT>
    os<C, CT>& operator<<(os<C, CT>& os, const TextFormatter& fmt)
    {
        const flag flags = ~fmt.mask & getCurrentTextAttributes() | fmt.attrs;
        setTextAttributes(flags);
        return os;
    }
}
