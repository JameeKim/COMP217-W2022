/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "EnergyOrb.h"

#include <iostream>

EnergyOrb::EnergyOrb(int maxAmmo, int currentAmmo, int damage)
    : Weapon("Energy Orb", maxAmmo, currentAmmo, damage)
{
}

void EnergyOrb::fire()
{
    printName();

    if (hasAmmo())
    {
        currentAmmo -= 1;
        std::cout << " is thrown" << std::endl;
    }
    else
    {
        std::cout << " is already exhausted" << std::endl;
    }
}
