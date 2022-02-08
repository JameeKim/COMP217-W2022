/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #4 (Wed. Feb. 02, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include "Daemon.h"

class RedDaemon : public Daemon
{
private:
    int redMagic;

public:
    RedDaemon(int health, int mana, int redMagic);

    void attack() override;
};
