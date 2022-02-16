/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #2 (Wed. Jan. 19, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

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

/// Save the current game state with the given save name
bool saveGame(const char* saveName);

/// Load the saved game state with the given save name
bool loadGame(const char* saveName);
