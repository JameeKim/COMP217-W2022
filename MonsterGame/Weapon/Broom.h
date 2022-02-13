/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include "Weapon.h"

class Broom : public Weapon
{
public:
    Broom(int maxAmmo, int currentAmmo, int damage);

    void fire() override;
};
