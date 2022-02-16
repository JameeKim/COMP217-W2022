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
    inSaves.exceptions(ios::failbit | ios::badbit);

    try
    {
        inSaves.open(saveName);
    }
    catch (ifstream::failure& error)
    {
        cerr << "Failed to open save file at " << saveName << endl;
        cerr << error.what() << endl;
        return false;
    }

    string name, playerType;
    int id, health, mana;
    Location location;

    try
    {
        getline(inSaves, name);
        inSaves >> id;
        cout << "ID " << id << endl;
        inSaves.ignore(numeric_limits<streamsize>::max(), EOL);
        getline(inSaves, playerType);
        cout << "Player type " << playerType << endl;
        inSaves >> location.x;
        inSaves.ignore(numeric_limits<streamsize>::max(), EOL);
        inSaves >> location.y;
        inSaves.ignore(numeric_limits<streamsize>::max(), EOL);
        inSaves >> location.z;
        inSaves.ignore(numeric_limits<streamsize>::max(), EOL);
        cout << "Location " << location.x << " " << location.y << " " << location.z << endl;
        inSaves >> health;
        cout << "Health " << health << endl;
        inSaves.ignore(numeric_limits<streamsize>::max(), EOL);
        inSaves >> mana;
        cout << "Mana " << mana << endl;
        inSaves.close();
    }
    catch (ifstream::failure& error)
    {
        cerr << "Failed to read save file at " << saveName << endl;
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
