/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #2 (due Tue. Jan. 25, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "GameUtilities.h"
#include "Weapon.cpp"

/// A player object
class Player
{
private:
    int id;
    int health;
    int mana;
    std::string username;
    Location location;

    // Lab 2: added attributes
    int avatar;
    std::string player_type;
    long spawnTime;
    std::vector<Weapon> weapons;

public:
    Player(
        int id,
        int health,
        int mana,
        std::string username,
        Location location,
        int avatar,
        std::string type,
        long spawnTime)
    {
        this->id = id;
        this->health = health;
        this->mana = mana;
        this->username = username;
        this->location = location;

        std::cout << "Player #" << this->id << " has been created" << std::endl;
    }

    int getId() const { return this->id; }
    int getHealth() const { return this->health; }
    int getMana() const { return this->mana; }
    std::string getUsername() { return this->username; }
    Location getLocation() const { return this->location; }

    bool isAlive() const { return this->health > 0; }

    void attack()
    {
        std::cout << "Player #" << this->id << " is attacking" << std::endl;
    }

    // Lab 2: added methods

    void moveTo(Location point)
    {
        std::cout << "Player #" << this->id << " is moving to: "
            << point.x << ", " << point.y << ", " << point.z << std::endl;
    }

    long getSpawnTime() const { return this->spawnTime; }
};
