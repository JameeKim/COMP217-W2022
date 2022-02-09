/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Queen.h"

Queen::Queen(
    int id,
    const std::string& username,
    int health,
    int mana,
    const std::vector<Weapon*>& weapons,
    const Location& location)
    : Player(id, username, health, mana, weapons, location)
{
    this->playerType = "Queen";
}

Queen::~Queen()
{
}
