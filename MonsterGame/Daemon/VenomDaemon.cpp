/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #4 (Wed. Feb. 02, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>

#include "VenomDaemon.h"

VenomDaemon::VenomDaemon(int health, int mana, int venom) : Daemon(health, mana)
{
    this->venom = venom;
}

void VenomDaemon::attack()
{
    std::cout << "Venom monster is attacking" << std::endl;
}
