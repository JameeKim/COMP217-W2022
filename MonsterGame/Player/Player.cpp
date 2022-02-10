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
    const int health,
    const int mana,
    std::vector<Weapon*> weapons,
    const Location& location)
    : playerType("Player"),
      id(id),
      location(location),
      health(health),
      mana(mana),
      weapons(std::move(weapons)),
      currentWeapon(weapons.size() > 0 ? weapons[0] : nullptr)
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
    if (!currentWeapon)
    {
        printTypeAndId();
        std::cout << " does not have any weapon" << std::endl;
        return;
    }

    if (currentWeapon->hasAmmo())
    {
        printTypeAndId();
        std::cout << " attacks" << std::endl;
        currentWeapon->fire();
    }
}

void Player::move(const Location& amount)
{
    location += amount;
}

void Player::addWeapon(Weapon* weapon)
{
    weapons.push_back(weapon);
}

Weapon* Player::swapWeapon(Weapon* weapon)
{
    // do nothing if the weapon is not found
    if (!hasWeapon(weapon))
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
