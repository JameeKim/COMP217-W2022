/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include "Player.h"

class Witch : public Player
{
public:
    Witch(
        int id,
        int health,
        int mana,
        std::vector<Weapon*> weapons = std::vector<Weapon*>(3),
        const Location& location = {});
    ~Witch() override {}

    void move(const Location& amount) override;
};
