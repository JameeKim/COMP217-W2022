/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #2 (Wed. Jan. 19, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iostream>

#include "Player.h"

using namespace std;

Player::Player(int id, int health, int mana, string username, Location location)
{
    this->id = id;
    this->health = health;
    this->mana = mana;
    this->username = username;
    this->location = location;

    cout << "Player #" << this->id << " has been created" << endl;
}

void Player::attack()
{
    cout << "Player #" << this->id << " is attacking" << endl;
}
