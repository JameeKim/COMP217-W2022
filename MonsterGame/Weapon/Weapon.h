/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <string>

/// A weapon object
class Weapon
{
private:
    std::string name;
    int maxNumBullets;
    int numBullets;
    float damage;

public:
    Weapon(std::string name, int maxNumBullets, int numBullets, float damage);

    void fire();
    void reload();
};
