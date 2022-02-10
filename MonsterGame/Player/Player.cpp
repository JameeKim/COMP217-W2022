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
      mana(mana),
      currentWeapon(nullptr)
{
}

Player::~Player()
{
    for (const Weapon* weapon : weapons)
    {
        delete weapon;
    }
}

void Player::attack()
{
    printTypeAndId();
    std::cout << " attempts an attack" << std::endl << "  ";

    if (!currentWeapon)
    {
        std::cout << "Fail: no weapon found" << std::endl << "  ";
        actionWhenNoWeapon();
        return;
    }

    std::cout << "Currently holding ";
    currentWeapon->printName();
    std::cout << std::endl << "  ";

    // the check for ammo is done in Weapon::fire so that it can display
    // appropriate messages depending on its type
    currentWeapon->fire();
}

void Player::move(const Location& amount)
{
    location += amount;
}

void Player::addWeapon(Weapon* weapon)
{
    weapons.push_back(weapon);

    // set the weapon as active if the player didn't have any before
    if (weapons.size() == 1)
    {
        currentWeapon = weapon;
    }
}

Weapon* Player::swapWeapon(Weapon* weapon)
{
    // do nothing if a weapon is given but not found
    if (weapon && !hasWeapon(weapon))
    {
        return nullptr;
    }

    // swap the weapons
    Weapon* previousWeapon = currentWeapon;
    currentWeapon = weapon;
    return previousWeapon;
}

void Player::printTypeAndId() const
{
    std::cout << playerType << " #" << id;
}

bool Player::hasWeapon(const Weapon* weapon) const
{
    const auto it = find(weapons.begin(), weapons.end(), weapon);
    return it != weapons.end();
}
