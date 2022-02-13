/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #4 (Wed. Feb. 02, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>
#include <vector>

#include "Team.h"
#include "Player/Player.h"
#include "Player/PlayerFactory.h"

constexpr size_t NUM_PLAYERS = 100;

int main(int argc, char* argv[])
{
    std::cout << "Welcome to Monster Game" << std::endl << std::endl;

    std::cout << "Weapon types:" << std::endl;
    std::cout << "  - Rusty Sword: 🗡️" << std::endl;
    std::cout << "  - Royal Gun: 🔫" << std::endl;
    std::cout << "  - Magic Wand: 🍭" << std::endl;
    std::cout << "  - Broom: 🧹" << std::endl;
    std::cout << "  - Energy Orb: 🔮" << std::endl;
    std::cout << "  - Laser Gun: 🕶️" << std::endl << std::endl;

    std::cout << "Player types:" << std::endl;
    std::cout << "  - Queen: 👑 - 🗡️🔫" << std::endl;
    std::cout << "  - Witch: 🧙 - 🗡️🍭🧹" << std::endl;
    std::cout << "  - Monk: 🧘 - 🗡️🔮🕶️" << std::endl << std::endl;

    std::vector<Player*> players = std::vector<Player*>(NUM_PLAYERS);

    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        // weapons are added in this function from "Player/PlayerFactory.h"
        players[i] = generateRandomPlayer(i + 1);
    }

    std::cout << "Generated " << NUM_PLAYERS << " players" << std::endl;
    const Team team = Team(players.data(), NUM_PLAYERS);

    std::cout << "Starting the attack of the team" << std::endl << std::endl;
    team.attack();

    return 0;
}
