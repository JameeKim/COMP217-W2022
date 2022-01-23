/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #2 (due Tue. Jan. 25, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>
#include <string>

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
    Player(int id, int health, int mana, std::string username, Location location = {})
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
};
