/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "EnergyOrb.h"

#include <iostream>

EnergyOrb::EnergyOrb(const int maxAmmo, const int currentAmmo, const int damage)
    : Weapon(maxAmmo, currentAmmo, damage)
{
}

const char* EnergyOrb::getName() const
{
    return "Energy Orb";
}

const char* EnergyOrb::getIcon() const
{
    return "🔮";
}

WEAPON_FIRE_DEFINE_HELPER(EnergyOrb, "is thrown", "is already exhausted");
