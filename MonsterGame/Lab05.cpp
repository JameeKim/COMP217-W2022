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
#include "Player/Monk.h"
#include "Player/Witch.h"

void lab05()
{
    std::cout << std::boolalpha;

    Player* p1 = new Monk(123, 20, 15, Location(-2, 1, 5));
    GameState::player = p1;

    const bool saveResult = saveGame("save1");
    std::cout << "Save game \"save1\": " << saveResult << std::endl;
    GameState::player = nullptr;

    if (!saveResult)
        return;

    const bool loadResult = loadGame("save1");
    std::cout << "Load game \"save1\": " << loadResult << std::endl;

    if (!loadResult)
        return;

    const Player* p2 = GameState::player;
    std::cout << "Player type: " << p2->getPlayerType() << std::endl;
    std::cout << "Player ID: " << p2->getId() << std::endl;
    std::cout << "Location: " << p2->getLocation() << std::endl;
    std::cout << "Health / Mana: " << p2->getHealth() << " / " << p2->getMana()
        << std::endl;
}
