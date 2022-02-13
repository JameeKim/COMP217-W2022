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

public:
    static const char* const success;
    static const char* const failure;

protected:
    int maxAmmo;
    int currentAmmo;
    int damage;

public:
    Weapon(int maxAmmo, int currentAmmo, int damage);
    virtual ~Weapon() = default;

    // getters

    virtual const char* getName() const;
    virtual const char* getIcon() const;
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

#define WEAPON_FIRE_DEFINE_HELPER(WeaponType, attackAction, outOfAmmoAction) \
    void WeaponType::fire() \
    { \
        printName(); \
        std::cout << " "; \
        if (hasAmmo()) \
        { \
            currentAmmo -= 1; \
            std::cout << attackAction << " " << Weapon::success; \
        } \
        else \
        { \
            std::cout << outOfAmmoAction << " " << Weapon::failure; \
        } \
    }
