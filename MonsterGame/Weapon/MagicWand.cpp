/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "MagicWand.h"

#include <iostream>

MagicWand::MagicWand(const int maxAmmo, const int currentAmmo, const int damage)
    : Weapon(maxAmmo, currentAmmo, damage)
{
}

const char* MagicWand::getName() const
{
    return "Magic Wand";
}

const char* MagicWand::getIcon() const
{
    return "🍭";
}

WEAPON_FIRE_DEFINE_HELPER(MagicWand, "emits a magic beam", "is out of charges");
