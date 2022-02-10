/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Witch.h"

#include <iostream>

Witch::Witch(
    const int id,
    const int health,
    const int mana,
    const Location& location)
    : Player(
        id,
        health,
        mana,
        location)
{
    playerType = "Witch";
}

void Witch::move(const Location& amount)
{
    Player::move(amount);
    printTypeAndId();
    std::cout << " flies" << std::endl;
}

void Witch::actionWhenNoWeapon() const
{
    printTypeAndId();
    std::cout << " goes poof and disappears" << std::endl;
}
