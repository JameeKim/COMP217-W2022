/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #4 (Wed. Feb. 02, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <vector>

#include "Team.h"
#include "Player/Player.h"
#include "Player/PlayerFactory.h"

constexpr size_t NUM_PLAYERS = 100;

int main(int argc, char* argv[])
{
    std::vector<Player*> players = std::vector<Player*>(NUM_PLAYERS);

    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        // weapons are added in this function from "Player/PlayerFactory.h"
        players[i] = generateRandomPlayer(i + 1);
    }

    const Team team = Team(players.data(), NUM_PLAYERS);
    team.attack();

    return 0;
}
