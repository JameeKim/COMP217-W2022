/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Weapon.h"

#include <iostream>

using namespace std;

Weapon::Weapon(string name, int maxAmmo, int currentAmmo, int damage)
{
    this->name = name;
    this->maxAmmo = maxAmmo;
    this->currentAmmo = currentAmmo;
    this->damage = damage;
}

void Weapon::fire()
{
    cout << "Weapon " << this->name << " is fired" << endl;
}

void Weapon::reload()
{
    this->currentAmmo = this->maxAmmo;
}
