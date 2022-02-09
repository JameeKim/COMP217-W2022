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
private:
    std::string weaponType;
    std::string name;

    int maxAmmo;
    int currentAmmo;
    int damage;

public:
    Weapon(std::string name, int maxAmmo, int currentAmmo, int damage);
    virtual ~Weapon() = default;

    bool hasAmmo() const { return this->currentAmmo > 0; }

    virtual void fire();
    void reload();
};
