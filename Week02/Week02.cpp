/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #2 (Wed. Jan. 19, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>
#include <vector>

#include "Player.h"

using namespace std;

/// Prints a line in std::cout about the location of the given player
void printPlayerLocation(const Player *p);

int main(int argc, char* argv[])
{
    // Pointers to the allocated memory spaces
    Player *p1 = new Player(1, 100, 100, "Dohyun", Location {});
    Player *p2 = new Player(2, 100, 100, "Alizera", Location { 2.0f, 3.0f, 0.0f });

    // An array-like data structure with a variable size
    vector<Player*> players = { p1 }; // initialize with an array
    players.push_back(p2); // add an item at the end

    // Print the stored location
    printPlayerLocation(players[0]);
    printPlayerLocation(players[1]);

    // Check if the players are alive
    cout << "Player #" << players[0]->getId() << " is alive: " << players[0]->isAlive() << endl;
    cout << "Player #" << players[1]->getId() << " is alive: " << players[1]->isAlive() << endl;

    // Perform attack methods on the players
    players[0]->attack();
    players[1]->attack();

    return 0;
}

void printPlayerLocation(const Player* p)
{
    const Location loc = p->getLocation();
    cout << "Player #" << p->getId() << " is at: " << loc.x << ", " << loc.y << ", " << loc.z << endl;
}