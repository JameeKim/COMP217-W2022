/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #4 (Wed. Feb. 02, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

class Daemon
{
private:
    int health;
    int mana;

public:
    Daemon(int health, int mana);

    int getHealth() const;

    virtual void attack() = 0;
};
