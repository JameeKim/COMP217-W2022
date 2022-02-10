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
    std::vector<Weapon*> weapons,
    const Location& location)
    : Player(
        id,
        health,
        mana,
        std::move(weapons),
        location)
{
    this->playerType = "Witch";
}

void Witch::move(const Location& amount)
{
    Player::move(amount);
    this->printTypeAndId();
    std::cout << " flies" << std::endl;
}
