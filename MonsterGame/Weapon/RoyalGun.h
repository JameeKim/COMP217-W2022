/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include "Weapon.h"

/**
 * A gun held by the Royal family
 */
class RoyalGun : public Weapon
{
public:
    RoyalGun(int maxAmmo, int currentAmmo, int damage);

    const char* getName() const override;
    const char* getIcon() const override;
};
