/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <string>
#include <vector>

#include "GameUtilities.h"

class Weapon;

/**
 * A player object
 */
class Player
{
protected:
    std::string playerType;

private:
    const int id;
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
        const Location& location = {});
    virtual ~Player() = 0;

    // getters
    const std::string& getPlayerType() const { return playerType; }
    int getId() const { return id; }
    const Location& getLocation() const { return location; }
    int getHealth() const { return health; }
    int getMana() const { return mana; }
    const std::vector<Weapon*>& getWeapons() const { return weapons; }
    Weapon* getCurrentWeapon() const { return currentWeapon; }

    // computed value getters
    bool isAlive() const { return health > 0; }

    // action methods
    /**
     * Activate current weapon
     */
    void attack();
    /**
     * Change the location and perform unique moves for each type (subclass)
     */
    virtual void move(const Location& amount = {});
    /**
     * Add the given weapon to the list of weapons the player possesses
     */
    void addWeapon(Weapon* weapon);
    /**
     * Swap the current active weapon to the given weapon and return the
     * previously active weapon
     */
    Weapon* swapWeapon(Weapon* weapon);

protected:
    void printTypeAndId() const;
    virtual void actionWhenNoWeapon() const = 0;

private:
    /**
     * Check if the given weapon is owned by the player
     */
    bool hasWeapon(const Weapon* weapon) const;
};
