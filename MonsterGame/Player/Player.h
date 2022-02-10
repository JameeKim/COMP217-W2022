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

/**
 * A player object
 */
class Player
{
protected:
    std::string playerType;

private:
    int id;
    Location location;

    int health;
    int mana;

    std::vector<Weapon*> weapons;
    Weapon* currentWeapon;

public:
    Player(
        int id,
        int health,
        int mana,
        std::vector<Weapon*> weapons = std::vector<Weapon*>(3),
        const Location& location = {});
    virtual ~Player() = 0;

    int getId() const { return this->id; }
    int getHealth() const { return this->health; }
    int getMana() const { return this->mana; }
    const Location& getLocation() const { return this->location; }
    const std::vector<Weapon*>& getWeapons() const { return this->weapons; }

    bool isAlive() const { return this->health > 0; }
    void attack();
    virtual void move(const Location& amount = {});

    void addWeapon(Weapon* weapon);
    /**
     * Swap the current active weapon to the given weapon and return the
     * previously active weapon
     */
    Weapon* swapWeapon(Weapon* weapon);

protected:
    void printTypeAndId() const;

private:
    /**
     * Check if the given weapon is owned by the player
     */
    bool hasWeapon(const Weapon* weapon) const;
};
