/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Weapon.h"

#include <iostream>

using namespace std;

Weapon::Weapon(string name, int maxNumBullets, int numBullets, float damage)
{
    this->name = name;
    this->maxNumBullets = maxNumBullets;
    this->numBullets = numBullets;
    this->damage = damage;

    cout << "Weapon " << this->name << " has been created" << endl;
}

void Weapon::fire()
{
    cout << "Weapon " << this->name << " is fired" << endl;
}

void Weapon::reload()
{
    cout << "Weapon " << this->name << " is reloaded" << endl;
}
