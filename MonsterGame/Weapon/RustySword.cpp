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
    : Weapon("Rusty Sword", maxAmmo, currentAmmo, damage)
{
}

WEAPON_FIRE_DEFINE_HELPER(
    RustySword,
    "is swung, but it tickles",
    "needs repair");
