/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include "Weapon.h"

/**
 * A powerful energy orb
 */
class EnergyOrb : public Weapon
{
public:
    EnergyOrb(int maxAmmo, int currentAmmo, int damage);

    void fire() override;
};
