/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #1
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <iostream>

namespace Explosive
{
    int power = 5;
    int damage = 2;
    float spawnTime = 3.0f;

    void explode()
    {
        std::cout << "The explosive just exploded" << std::endl;
    }

    void applyDamage()
    {
        std::cout << "The explosive is... damaged?" << std::endl;
    }
}
