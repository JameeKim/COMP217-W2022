/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #4 (Wed. Feb. 02, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include "Daemon.h"

class VenomDaemon: public Daemon
{
private:
    int venom;

public:
    VenomDaemon(int health, int mana, int venom);

    void attack() override;
};
