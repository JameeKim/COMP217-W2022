/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include "Weapon.h"

/**
 * Rusty and dull sword that can be swung by anyone
 */
class RustySword : public Weapon
{
public:
    RustySword(int maxAmmo, int currentAmmo, int damage);

    const char* getName() const override;
    const char* getIcon() const override;

    void fire() override;
};
