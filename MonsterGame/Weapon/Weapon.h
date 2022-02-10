/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <string>

/**
 * A weapon object
 */
class Weapon
{
    friend class Player;

private:
    std::string name;

protected:
    int maxAmmo;
    int currentAmmo;
    int damage;

public:
    Weapon(std::string name, int maxAmmo, int currentAmmo, int damage);
    virtual ~Weapon() = default;

    // getters

    const std::string& getName() const { return name; }
    int getMaxAmmo() const { return maxAmmo; }
    int getCurrentAmmo() const { return currentAmmo; }
    int getDamage() const { return damage; }

    // computed value getters
    bool hasAmmo() const { return currentAmmo > 0; }

    // action methods
    /**
     * Perform the associated attack move
     */
    virtual void fire();
    /**
     * Reload the ammo to the full capacity (maxAmmo)
     */
    void reload();

protected:
    void printName() const;
};
