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
