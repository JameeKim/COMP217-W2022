/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #2 (Wed. Jan. 19, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include "GameUtilities.h"

/// A player object
class Player
{
private:
    int id;
    int health;
    int mana;
    std::string username;
    Location location;

public:
    Player(int id, int health, int mana, std::string username, Location location = {});

    int getId() const { return this->id; }
    int getHealth() const { return this->health; }
    int getMana() const { return this->mana; }
    std::string getUsername() { return this->username; }
    Location getLocation() const { return this->location; }

    bool isAlive() const { return this->health > 0; }
    void attack();
};
