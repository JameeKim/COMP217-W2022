/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include "Player.h"

class Monk : public Player
{
public:
    Monk(
        int id,
        int health,
        int mana,
        const Location& location = {});
    ~Monk() override {}

    void move(const Location& amount = {}) override;

protected:
    void actionWhenNoWeapon() const override;
};
