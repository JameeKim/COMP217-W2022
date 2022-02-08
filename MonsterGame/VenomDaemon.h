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
