/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "MagicWand.h"

#include <iostream>

MagicWand::MagicWand(const int maxAmmo, const int currentAmmo, const int damage)
    : Weapon("Magic Wand", maxAmmo, currentAmmo, damage)
{
}

void MagicWand::fire()
{
    printName();

    if (hasAmmo())
    {
        currentAmmo -= 1;
        std::cout << " emits a magic beam" << std::endl;
    }
    else
    {
        std::cout << " is out of charges" << std::endl;
    }
}
