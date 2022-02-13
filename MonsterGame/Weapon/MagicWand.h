/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include "Weapon.h"

/**
 * A magic wand which requires deep knowledge and skill in magic
 */
class MagicWand : public Weapon
{
public:
    MagicWand(int maxAmmo, int currentAmmo, int damage);

    const char* getName() const override;
    const char* getIcon() const override;

    void fire() override;
};
