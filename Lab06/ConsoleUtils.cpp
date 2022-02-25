/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "ConsoleUtils.h"

#include <string>
#include <Windows.h>

namespace console
{
    namespace format
    {
        /**
         * Cached pointer for handle to stdout
         */
        HANDLE handleCache = nullptr;

        /**
         * Get cached handle to stdout
         */
        HANDLE handle()
        {
            if (handleCache != nullptr)
                return handleCache;

            handleCache = GetStdHandle(STD_OUTPUT_HANDLE);

            if (handleCache != INVALID_HANDLE_VALUE)
                return handleCache;

            std::string msg = "Failed to get stdout handle (code ";
            msg += std::to_string(GetLastError());
            msg += ")";
            throw ConsoleUtilsError(msg);
        }

        WORD getTextAttributes()
        {
            CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

            if (GetConsoleScreenBufferInfo(handle(), &bufferInfo))
                return bufferInfo.wAttributes;

            std::string msg = "Failed to get console info (code ";
            msg += std::to_string(GetLastError());
            msg += ")";
            throw ConsoleUtilsError(msg);
        }

        void setTextAttributes(const flag attrs)
        {
            if (SetConsoleTextAttribute(handle(), attrs))
                return;

            std::string msg = "Failed to set console text attribute to ";
            msg += std::to_string(attrs);
            msg += " (code ";
            msg += std::to_string(GetLastError());
            msg += ")";
            throw ConsoleUtilsError(msg);
        }
    }
}
