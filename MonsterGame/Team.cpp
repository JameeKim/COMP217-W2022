/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Team.h"

#include "Player/Player.h"
#include "Player/PlayerFactory.h"

Team::Team(const size_t size): size(size)
{
    players = new Player*[size];

    for (int i = 0; i < size; i++)
    {
        players[i] = generateRandomPlayer(i + 1);
    }
}

Team::Team(Player* players[], const size_t size): players(players), size(size)
{
}

Team::~Team()
{
    for (int i = 0; i < size; i++)
    {
        delete players[i];
    }
}

void Team::attack() const
{
    for (int i = 0; i < size; i++)
    {
        players[i]->attack();
    }
}
