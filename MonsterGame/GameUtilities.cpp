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
    fstream outSaves;
    outSaves.exceptions(ios::failbit | ios::badbit);

    try
    {
        outSaves.open(GAME_SAVE_FILE);
    }
    catch (fstream::failure& error)
    {
        cerr << "Failed to open save file at " << GAME_SAVE_FILE << endl;
        cerr << error.what() << endl;
        return false;
    }

    bool saveFound = false;

    try
    {
        string name;
        while (outSaves.peek() != EOF && getline(outSaves, name))
        // EOF check is needed because getline sets failbit when it encounters
        // the EOF as its first input
        {
            if (name == saveName)
            {
                saveFound = true;
                cout << "Found save \"" << name << "\"" << endl;
                break;
            }
        }

        if (!saveFound)
        {
            outSaves.clear(); // clear EOF bit
            cout << "Save \"" << saveName << "\" not found; "
                << "creating a new save" << endl;
        }
    }
    catch (fstream::failure& error)
    {
        cerr << "Failed to read save file at " << GAME_SAVE_FILE << endl;
        cerr << error.what() << endl;
        return false;
    }

    try
    {
        fstream::pos_type pos = outSaves.tellg();
        outSaves.seekp(pos);

        if (!saveFound)
        {
            outSaves << saveName << endl;
        }

        if (const Player* player = GameState::player)
        {
            outSaves << player->getId() << endl;
            outSaves << player->getPlayerType() << endl;
            outSaves << player->getLocation().x << endl;
            outSaves << player->getLocation().y << endl;
            outSaves << player->getLocation().z << endl;
            outSaves << player->getHealth() << endl;
            outSaves << player->getMana() << endl;
        }
        outSaves.flush();
    }
    catch (fstream::failure& error)
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
        inSaves.open(GAME_SAVE_FILE, ios::out);
    }
    catch (ifstream::failure& error)
    {
        cerr << "Failed to open save file at " << GAME_SAVE_FILE << endl;
        cerr << error.what() << endl;
        return false;
    }

    string name, playerType;
    int id, health, mana;
    Location location;

    try
    {
        bool saveFound = false;
        while (inSaves.peek() != EOF && getline(inSaves, name))
        // EOF check is needed because getline sets failbit when it encounters
        // the EOF as its first input
        {
            if (name == saveName)
            {
                saveFound = true;
                break;
            }
        }

        if (!saveFound)
        {
            cerr << "Failed to find save \"" << saveName << "\"" << endl;
            return false;
        }

        // read id
        inSaves >> id;
        inSaves.ignore(numeric_limits<streamsize>::max(), EOL);

        // read player type
        getline(inSaves, playerType);

        // read location
        inSaves >> location.x;
        inSaves.ignore(numeric_limits<streamsize>::max(), EOL);
        inSaves >> location.y;
        inSaves.ignore(numeric_limits<streamsize>::max(), EOL);
        inSaves >> location.z;
        inSaves.ignore(numeric_limits<streamsize>::max(), EOL);

        // read health
        inSaves >> health;
        inSaves.ignore(numeric_limits<streamsize>::max(), EOL);

        // read mana
        inSaves >> mana;
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
    }

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
