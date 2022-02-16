/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #5 (due Thu. Feb. 17, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "GameUtilities.h"

#include <fstream>
#include <iostream>
#include <string>

#include "Game/GameState.h"
#include "Player/Monk.h"
#include "Player/Player.h"
#include "Player/Queen.h"
#include "Player/Witch.h"

using namespace std;

constexpr char GAME_SAVE_FILE[] = "gameData.txt";
constexpr char EOL = '\n';

bool saveGame(const char* saveName)
{
    ofstream outSaves;
    outSaves.exceptions(ios::failbit | ios::badbit);

    try
    {
        outSaves.open(GAME_SAVE_FILE);
    }
    catch (ofstream::failure& error)
    {
        cerr << "Failed to open save file at " << GAME_SAVE_FILE << endl;
        cerr << error.what() << endl;
        return false;
    }

    try
    {
        outSaves << saveName << EOL;
        if (const Player* player = GameState::player)
        {
            outSaves << player->getId() << EOL
                << player->getPlayerType() << EOL
                << player->getLocation() << EOL
                << player->getHealth() << EOL
                << player->getMana() << EOL;
        }
        outSaves << flush;
    }
    catch (ofstream::failure& error)
    {
        cerr << "Failed to write to save file at " << GAME_SAVE_FILE << endl;
        cerr << error.what() << endl;
        return false;
    }

    return true;
}

bool loadGame(const char* saveName)
{
    ifstream inSaves;
    inSaves.exceptions(ios::failbit | ios::badbit);

    try
    {
        inSaves.open(GAME_SAVE_FILE);
    }
    catch (ifstream::failure& error)
    {
        cerr << "Failed to open save file at " << GAME_SAVE_FILE << endl;
        cerr << error.what() << endl;
        return false;
    }

    string playerType;
    int id, health, mana;
    Location location;

    try
    {
        string name;
        getline(inSaves, name);

        if (name != saveName)
        {
            cerr << "Cannot find save \"" << saveName << "\"" << endl;
            return false;
        }

        inSaves >> id >> ws
            >> playerType >> ws
            >> location >> ws
            >> health >> ws
            >> mana >> ws;

        inSaves.close();
    }
    catch (ifstream::failure& error)
    {
        cerr << "Failed to read save file at " << GAME_SAVE_FILE << endl;
        cerr << error.what() << endl;
        return false;
    }

#define IF_PLAYER_TYPE_EQUALS(PType) \
    if (playerType == #PType) \
    { \
        GameState::player = new PType(id, health, mana, location); \
    } \

    IF_PLAYER_TYPE_EQUALS(Queen)
    else IF_PLAYER_TYPE_EQUALS(Witch)
    else IF_PLAYER_TYPE_EQUALS(Monk)
    else
    {
        cerr << "Unknown player type \"" << playerType << "\"" << endl;
        return false;
    }

    return true;
}
