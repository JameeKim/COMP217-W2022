/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

class Player;

class Team
{
private:
    Player** players;
    size_t size;

public:
    Team(size_t size);
    ~Team();

    void attack() const;
};
