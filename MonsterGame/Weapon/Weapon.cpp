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
    : weaponType("Weapon"),
      name(std::move(name)),
      maxAmmo(maxAmmo),
      currentAmmo(currentAmmo),
      damage(damage)
{
}

void Weapon::fire()
{
    if (hasAmmo())
    {
        currentAmmo -= 1;
    }
    std::cout << weaponType << " \"" << name << "\" is fired" << std::endl;
}

void Weapon::reload()
{
    currentAmmo = maxAmmo;
}
