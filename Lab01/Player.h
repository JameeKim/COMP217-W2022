/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #1
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <iostream>

namespace Player
{
    int health = 10;
    int damage = 3;
    int manaPower = 5;

    void attack()
    {
        std::cout << "Player attacks with damage of " << damage << std::endl;
    }

    void applyDamage()
    {
        if (health <= 0)
        {
            std::cout << "You're dead, but something still wants to hit you. Bruh" << std::endl;
            return;
        }

        health -= 1;
        std::cout << "Player is damaged; health is now " << health << std::endl;

        if (health <= 0)
        {
            std::cout << "You're dead. F" << std::endl;
        }
    }
}
