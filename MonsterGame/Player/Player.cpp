/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>

#include "Player.h"

#include "Weapon/Weapon.h"

Player::Player(
    const int id,
    const int health,
    const int mana,
    const Location& location)
    : playerType("Player"),
      id(id),
      location(location),
      health(health),
      mana(mana)
{
    weapons.reserve(3);
}

Player::~Player()
{
    for (const Weapon* weapon : weapons)
    {
        delete weapon;
    }
}

void Player::attack() const
{
    printTypeAndId();
    std::cout << " attempts an attack (has " << weapons.size() << " weapons)"
        << " - ";

    if (weapons.empty())
    {
        actionWhenNoWeapon();
    }
    else
    {
        // the check for ammo is done in Weapon::fire so that it can display
        // appropriate messages depending on its type
        weapons.front()->fire();
    }

    std::cout << std::endl;
}

void Player::move(const Location& amount)
{
    location += amount;
}

void Player::addWeapon(Weapon* weapon)
{
    // don't add if the player already has 3
    if (weapons.size() >= 3)
    {
        std::cout << "Cannot add more weapons to ";
        printTypeAndId();
        std::cout << ": already has " << weapons.size() << std::endl;
        return;
    }

    weapons.push_back(weapon);
}

Weapon* Player::swapWeapon(Weapon* weapon)
{
    if (!weapon || weapons.size() <= 0)
    {
        return nullptr;
    }

    const size_t idx = weaponPosition(weapon);
    if (idx >= weapons.size())
    {
        return nullptr;
    }

    Weapon* previousWeapon = weapons[0];
    std::swap(weapons[0], weapons[idx]);
    return previousWeapon;
}

void Player::printTypeAndId() const
{
    std::cout << playerType << " #" << id;
}

size_t Player::weaponPosition(const Weapon* weapon) const
{
    const auto it = std::find(weapons.begin(), weapons.end(), weapon);
    return std::distance(weapons.begin(), it);
}
