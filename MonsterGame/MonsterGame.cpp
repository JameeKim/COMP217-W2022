/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #4 (Wed. Feb. 02, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <vector>

#include "Daemon/Daemon.h"
#include "Daemon/RedDaemon.h"
#include "Daemon/VenomDaemon.h"
#include "Player/Player.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<Daemon*> daemons;
    daemons.push_back(new RedDaemon(10, 10, 1));
    daemons.push_back(new VenomDaemon(5, 10, 3));

    daemons[0]->attack();
    daemons[1]->attack();

    // de-allocate objects
    for (const Daemon* daemon : daemons)
    {
        delete daemon;
    }

    return 0;
}
