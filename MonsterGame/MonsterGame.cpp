#include <vector>

#include "Daemon.h"
#include "RedDaemon.h"
#include "VenomDaemon.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<Daemon*> daemons;
    daemons.push_back(new RedDaemon(10, 10, 1));
    daemons.push_back(new VenomDaemon(5, 10, 3));

    daemons[0]->attack();
    daemons[1]->attack();

    return 0;
}
