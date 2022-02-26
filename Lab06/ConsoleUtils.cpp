/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "ConsoleUtils.h"

#include <Windows.h>

namespace console
{
    namespace format
    {
        std::pair<flag, bool> getTextAttributes()
        {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

            if (handle == INVALID_HANDLE_VALUE)
                return { 0, false };

            CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
            const bool res = GetConsoleScreenBufferInfo(handle, &bufferInfo);
            return { bufferInfo.wAttributes, res };
        }

        bool setTextAttributes(const flag attrs)
        {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

            if (handle == INVALID_HANDLE_VALUE)
                return false;

            const bool res = SetConsoleTextAttribute(handle, attrs);
            return res;
        }
    }
}
