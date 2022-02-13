/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Weapon.h"

#include <iostream>

Weapon::Weapon(
    std::string name,
    const int maxAmmo,
    const int currentAmmo,
    const int damage)
    : name(std::move(name)),
      maxAmmo(maxAmmo),
      currentAmmo(currentAmmo),
      damage(damage)
{
}

WEAPON_FIRE_DEFINE_HELPER(Weapon, "is fired", "is out of ammo");

void Weapon::reload()
{
    currentAmmo = maxAmmo;
    printName();
    std::cout << " is reloaded: fully charged at " << currentAmmo << std::endl;
}

void Weapon::printName() const
{
    std::cout << "Weapon \"" << name << "\"";
}
