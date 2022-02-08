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
