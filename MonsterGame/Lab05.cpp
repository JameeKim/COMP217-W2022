/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #5 (due Thu. Feb. 17, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Lab05.h"

#include <iostream>

#include "GameUtilities.h"
#include "Game/GameState.h"
#include "Player/Witch.h"

void lab05()
{
    Player* p1 = new Witch(123, 20, 15, Location(-2, 1, 5));
    GameState::player = p1;

    std::cout << "Save game: " << saveGame("gameData.txt") << std::endl;
    GameState::player = nullptr;

    std::cout << "Load game: " << loadGame("gameData.txt") << std::endl;
    const Player* p2 = GameState::player;
    std::cout << "Player type: " << p2->getPlayerType() << std::endl;
    std::cout << "Player ID: " << p2->getId();
}
