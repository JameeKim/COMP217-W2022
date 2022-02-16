/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #5 (due Thu. Feb. 17, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "GameUtilities.h"

#include <fstream>
#include <iostream>

#include "Game/GameState.h"
#include "Player/Player.h"

using namespace std;

constexpr char GAME_SAVE_FILE[] = "gameData.txt";
constexpr char EOL = '\n';

bool saveGame(const char* saveName)
{
    ofstream outSaves;
    outSaves.exceptions(ios::failbit | ios::badbit);

    try
    {
        outSaves.open(saveName);
    }
    catch (ofstream::failure& error)
    {
        cerr << "Failed to open save file at " << saveName << endl;
        cerr << error.what() << endl;
        return false;
    }

    try
    {
        outSaves << saveName << EOL;
        if (const Player* player = GameState::player)
        {
            outSaves << player->getId() << EOL;
            outSaves << player->getPlayerType() << EOL;
            outSaves << player->getLocation().x << EOL;
            outSaves << player->getLocation().y << EOL;
            outSaves << player->getLocation().z << EOL;
            outSaves << player->getHealth() << EOL;
            outSaves << player->getMana() << EOL;
        }
        outSaves.flush();
    }
    catch (ofstream::failure& error)
    {
        cerr << "Failed to write to save file at " << saveName << endl;
        cerr << error.what() << endl;
        return false;
    }

    return true;
}

bool loadGame(const char* saveName)
{
    ifstream inSaves;
    inSaves.open(GAME_SAVE_FILE);
    inSaves.close();
    return true;
}
