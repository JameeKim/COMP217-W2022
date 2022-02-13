/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "LaserGun.h"

#include <iostream>

LaserGun::LaserGun(const int maxAmmo, const int currentAmmo, const int damage)
    : Weapon("Laser Gun", maxAmmo, currentAmmo, damage)
{
}

WEAPON_FIRE_DEFINE_HELPER(LaserGun, "goes pew pew", "ran out of battery power");
