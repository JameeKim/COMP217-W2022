/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Monk.h"

#include <iostream>

Monk::Monk(
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
    playerType = "Monk";
}

void Monk::move(const Location& amount)
{
    Player::move(amount);
    printTypeAndId();
    std::cout << " moves as a spirit" << std::endl;
}
