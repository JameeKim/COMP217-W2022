/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #4 (Wed. Feb. 02, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>
#include <vector>

#include "Player/Player.h"
#include "Player/PlayerFactory.h"

constexpr size_t NUM_PLAYERS = 10;

int main(int argc, char* argv[])
{
    std::vector<Player*> players = std::vector<Player*>(NUM_PLAYERS);
    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        players[i] = generateRandomPlayer(i + 1);
    }

    // move
    for (Player* player : players)
    {
        player->attack();
    }

    // de-allocate objects
    for (const Player* player : players)
    {
        delete player;
    }

    return 0;
}
