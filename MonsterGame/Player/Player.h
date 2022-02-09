/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <vector>

#include "GameUtilities.h"
#include "Weapon/Weapon.h"

/// A player object
class Player
{
protected:
    std::string playerType;

private:
    int id;
    std::string username;
    Location location;

    int health;
    int mana;

    std::vector<Weapon*> weapons;
    Weapon* currentWeapon;

public:
    Player(
        int id,
        std::string username,
        int health,
        int mana,
        std::vector<Weapon*> weapons = std::vector<Weapon*>(3),
        const Location& location = {});
    virtual ~Player();

    int getId() const { return this->id; }
    int getHealth() const { return this->health; }
    int getMana() const { return this->mana; }
    const std::string& getUsername() { return this->username; }
    const Location& getLocation() const { return this->location; }
    const std::vector<Weapon*>& getWeapons() const { return this->weapons; }

    bool isAlive() const { return this->health > 0; }
    void attack();
    virtual void move(const Location& amount = {});

    void addWeapon(Weapon* weapon);
    /**
     * Swap the current active weapon to the given weapon and return the previously active weapon
     */
    Weapon* swapWeapon(Weapon* weapon);
};
