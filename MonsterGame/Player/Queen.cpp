/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Queen.h"

#include <iostream>

Queen::Queen(
    int id,
    std::string username,
    int health,
    int mana,
    std::vector<Weapon*> weapons,
    const Location& location)
    : Player(
        id,
        std::move(username),
        health,
        mana,
        std::move(weapons),
        location)
{
    this->playerType = "Queen";
}

void Queen::move(const Location& amount)
{
    Player::move(amount);
    this->printTypeAndId();
    std::cout << " moves with with spare" << std::endl;
}
