/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #4 (Wed. Feb. 02, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>

#include "RedDaemon.h"

RedDaemon::RedDaemon(int health, int mana, int redMagic) : Daemon(health, mana)
{
    this->redMagic = redMagic;
}

void RedDaemon::attack()
{
    std::cout << "Red daemon is attacking" << std::endl;
}
