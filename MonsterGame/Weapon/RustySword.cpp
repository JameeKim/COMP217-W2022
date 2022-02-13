/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "RustySword.h"

#include <iostream>

RustySword::RustySword(
    const int maxAmmo,
    const int currentAmmo,
    const int damage)
    : Weapon(maxAmmo, currentAmmo, damage)
{
}

const char* RustySword::getName() const
{
    return "Rusty Sword";
}

const char* RustySword::getIcon() const
{
    return "🗡️";
}

WEAPON_FIRE_DEFINE_HELPER(
    RustySword,
    "is swung, but it tickles",
    "needs repair");
