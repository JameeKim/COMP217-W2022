/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <functional>
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

    // Type alias for concise code
    template <class C, class CT>
    using os = std::basic_ostream<C, CT>;

    /**
     * Helper for setting text formats
     */
    namespace format
    {
        /**
         * Type alias for text format attribute flags
         */
        using flag = WORD;

        /**
         * Get current text attributes
         */
        flag getTextAttributes();

        /**
         * Set text attributes
         */
        void setTextAttributes(flag attrs);

        enum flags : flag
        {
            red = FOREGROUND_RED,
            blue = FOREGROUND_BLUE,
            green = FOREGROUND_GREEN,
            white = red | blue | green,
            strong = FOREGROUND_INTENSITY,
            fg = white | strong,

            bg_red = BACKGROUND_RED,
            bg_blue = BACKGROUND_BLUE,
            bg_green = BACKGROUND_GREEN,
            bg_white = bg_red | bg_blue | bg_green,
            bg_strong = BACKGROUND_INTENSITY,
            bg = bg_white | bg_strong,

            reverse = COMMON_LVB_REVERSE_VIDEO,
            style_mask = reverse,

            all = fg | bg | style_mask,
            none = 0x0000,
            pass = 0xFFFF,
        };

        /**
         * IO manipulator for windows console colors
         */
        class TextFmt
        {
        public:
            explicit TextFmt(const flag attrs, const flag mask)
                : attrs(attrs & mask), mask(mask) {}

            /**
             * Operator overloading for changing windows console colors
             */
            template <class C, class CT>
            friend os<C, CT>& operator<<(os<C, CT>& os, const TextFmt& fmt)
            {
                const flag flags = ~fmt.mask & getTextAttributes() | fmt.attrs;
                setTextAttributes(flags);
                return os;
            }

        private:
            flag attrs;
            flag mask;
        };

        /**
         * Helper function to intensify the foreground color
         */
        inline TextFmt bold()
        {
            return TextFmt(strong, strong);
        }

        /**
         * Helper function to reset bold
         */
        inline TextFmt noBold()
        {
            return TextFmt(none, strong);
        }

        /**
         * Helper function to set the color of the text
         */
        inline TextFmt color(const flag c)
        {
            return TextFmt(c, white);
        }

        /**
         * Helper function to revert the color of the text (to white)
         */
        inline TextFmt noColor()
        {
            return color(white);
        }

        /**
         * Helper function to highlight the text by reversing fg and bg
         */
        inline TextFmt highlight()
        {
            return TextFmt(reverse, reverse);
        }

        /**
         * Helper function to un-highlight the text
         */
        inline TextFmt noHighlight()
        {
            return TextFmt(none, reverse);
        }
    }
}
