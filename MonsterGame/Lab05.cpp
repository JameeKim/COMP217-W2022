/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #5 (due Thu. Feb. 17, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "Lab05.h"

#include <fstream>
#include <iostream>

#include "GameUtilities.h"
#include "Game/GameState.h"
#include "Player/Witch.h"

void lab05()
{
    GameState::player = new Witch(123, 20, 15, { -2, 1, 5 });
    saveGame("gameData.txt");
}
