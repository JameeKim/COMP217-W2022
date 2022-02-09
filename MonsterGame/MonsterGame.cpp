/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #4 (Wed. Feb. 02, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>
#include <vector>

#include "Player/Player.h"
#include "Player/Queen.h"

constexpr size_t NUM_PLAYERS = 5;

int main(int argc, char* argv[])
{
    std::vector<Player*> players = std::vector<Player*>(NUM_PLAYERS);
    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        players.push_back(new Queen(i + 1, "jameekim", 10, 10));
    }

    // move
    for (Player* player : players)
    {
        player->move();
    }

    // de-allocate objects
    for (const Player* player : players)
    {
        delete player;
    }

    return 0;
}
