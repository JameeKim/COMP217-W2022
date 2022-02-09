/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>

#include "Player.h"

Player::Player(
    const int id,
    std::string username,
    const int health,
    const int mana,
    std::vector<Weapon*> weapons,
    const Location& location)
{
    this->playerType = "Player";

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
        this->printTypeAndId();
        std::cout << " does not have any weapon" << std::endl;
        return;
    }

    if (this->currentWeapon->hasAmmo())
    {
        this->printTypeAndId();
        std::cout << " attacks" << std::endl;
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
    // do nothing if the weapon is not found
    if (!this->hasWeapon(weapon))
    {
        return nullptr;
    }

    // swap the weapons
    Weapon* previousWeapon = this->currentWeapon;
    this->currentWeapon = weapon;
    return previousWeapon;
}

void Player::printTypeAndId() const
{
    std::cout << this->playerType << " #" << this->id;
}

bool Player::hasWeapon(const Weapon* weapon) const
{
    const auto it = find(this->weapons.begin(), this->weapons.end(), weapon);
    return it != this->weapons.end();
}
