/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>

#include "Player.h"

using namespace std;

Player::Player(
    const int id,
    string username,
    const int health,
    const int mana,
    vector<Weapon*> weapons,
    const Location& location)
{
    this->id = id;
    this->username = std::move(username);
    this->location = location;

    this->health = health;
    this->mana = mana;

    this->weapons = std::move(weapons);
    this->currentWeapon = weapons.size() > 0 ? weapons[0] : nullptr;
}

Player::~Player()
{
    for (const Weapon* weapon : this->weapons)
    {
        delete weapon;
    }
}

void Player::attack()
{
    if (!this->currentWeapon)
    {
        cout << this->playerType << " #" << this->id << " does not have any weapon" << endl;
        return;
    }

    if (this->currentWeapon->hasAmmo())
    {
        cout << this->playerType << " #" << this->id << " attacks" << endl;
        this->currentWeapon->fire();
    }
}

void Player::move(const Location& amount)
{
    this->location += amount;
}

void Player::addWeapon(Weapon* weapon)
{
    weapons.push_back(weapon);
}

Weapon* Player::swapWeapon(Weapon* weapon)
{
    // check if the weapon is owned by the player
    const std::vector<Weapon*>::iterator it = find(this->weapons.begin(), this->weapons.end(), weapon);
    if (it == this->weapons.end())
    {
        // do nothing if the weapon is not found
        return nullptr;
    }

    // swap the weapons
    Weapon* previousWeapon = this->currentWeapon;
    this->currentWeapon = weapon;
    return previousWeapon;
}
