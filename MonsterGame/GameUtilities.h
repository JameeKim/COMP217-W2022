/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #2 (Wed. Jan. 19, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <istream>
#include <ostream>

/// A location in a 3D space
struct Location
{
    float x;
    float y;
    float z;

    Location(): x(0.0f), y(0.0f), z(0.0f) {}
    Location(float x, float y, float z = 0.0f): x(x), y(y), z(z) {}

    Location operator+(const Location& rhs) const
    {
        return Location(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    Location& operator+=(const Location& rhs)
    {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        return *this;
    }
};

/// Operator overloading for outputting Location to a stream
template <class Elem, class Traits>
std::basic_ostream<Elem, Traits>& operator<<(
    std::basic_ostream<Elem, Traits>& oStream,
    const Location& location)
{
    static const char* space = " ";
    oStream << location.x << space << location.y << space << location.z;
    return oStream;
}

/// Operator overloading for parsing Location from a stream
template <class Elem, class Traits>
std::basic_istream<Elem, Traits>& operator>>(
    std::basic_istream<Elem, Traits>& iStream,
    Location& location)
{
    iStream >> location.x >> std::ws >> location.y >> std::ws >> location.z;
    return iStream;
}

/// Save the current game state with the given save name
bool saveGame(const char* saveName);

/// Load the saved game state with the given save name
bool loadGame(const char* saveName);
