/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #5 (due Thu. Feb. 17, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <string>

class Player;

/// Game state
class GameState
{
public:
    /// Name of the save; empty string if not set
    static std::string saveName;

    /// The player
    static Player* player;
};
