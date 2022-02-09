/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #4 (Wed. Feb. 02, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>
#include <vector>

#include "Daemon/Daemon.h"
#include "Daemon/RedDaemon.h"
#include "Daemon/VenomDaemon.h"

#include "Week05.h"

int main(int argc, char* argv[])
{
    std::vector<Daemon*> daemons;
    daemons.push_back(new RedDaemon(10, 10, 1));
    daemons.push_back(new VenomDaemon(5, 10, 3));

    daemons[0]->attack();
    daemons[1]->attack();

    fileIO();
    fileCursor();
    writeBlock();

    // de-allocate objects
    for (const Daemon* daemon : daemons)
    {
        delete daemon;
    }

    return 0;
}
