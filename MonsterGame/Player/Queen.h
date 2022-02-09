/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include "Player.h"

class Queen : public Player
{
public:
    Queen(
        int id,
        std::string username,
        int health,
        int mana,
        std::vector<Weapon*> weapons = std::vector<Weapon*>(3),
        const Location& location = {});
    ~Queen() override {}

    void move(const Location& amount) override;
};
