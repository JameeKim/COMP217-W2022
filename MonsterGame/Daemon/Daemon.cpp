/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #4 (Wed. Feb. 02, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Daemon.h"

Daemon::Daemon(int health, int mana)
{
    this->health = health;
    this->mana = mana;
}

int Daemon::getHealth() const
{
    return this->health;
}
