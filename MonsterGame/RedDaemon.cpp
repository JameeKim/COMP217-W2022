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
