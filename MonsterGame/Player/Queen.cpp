/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Queen.h"

#include <iostream>

Queen::Queen(
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
    playerType = "Queen";
}

void Queen::move(const Location& amount)
{
    Player::move(amount);
    printTypeAndId();
    std::cout << " moves with with spare" << std::endl;
}

void Queen::actionWhenNoWeapon() const
{
    printTypeAndId();
    std::cout << " prepares to guard oneself" << std::endl;
}
