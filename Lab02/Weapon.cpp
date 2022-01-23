/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #2 (due Tue. Jan. 25, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <iostream>

/// A weapon object
class Weapon
{
private:
    std::string name;
    int maxNumBullets;
    int numBullets;
    float damage;

public:
    Weapon(std::string name, int maxNumBullets, int numBullets, float damage)
    {
        this->name = name;
        this->maxNumBullets = maxNumBullets;
        this->numBullets = numBullets;
        this->damage = damage;

        std::cout << "Weapon " << this->name << " has been created" << std::endl;
    }

    void fire()
    {
        std::cout << "Weapon " << this->name << " is fired" << std::endl;
    }

    void reload()
    {
        std::cout << "Weapon " << this->name << " is reloaded" << std::endl;
    }
};
