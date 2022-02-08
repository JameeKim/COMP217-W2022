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
