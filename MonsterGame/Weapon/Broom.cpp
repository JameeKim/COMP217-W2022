/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Broom.h"

#include <iostream>

Broom::Broom(const int maxAmmo, const int currentAmmo, const int damage)
    : Weapon(maxAmmo, currentAmmo, damage)
{
}

const char* Broom::getName() const
{
    return "Broom";
}

const char* Broom::getIcon() const
{
    return "🧹";
}

WEAPON_FIRE_DEFINE_HELPER(Broom, "sweeps the area", "needs charge");
