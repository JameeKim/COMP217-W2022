/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "PlayerFactory.h"

#include <functional>
#include <random>

#include "Monk.h"
#include "Queen.h"
#include "Witch.h"

/**
 * Macro for creating lambdas that call constructors of Player subclasses
 */
#define PLAYER_CREATOR(Type) \
    Player* make##Type(const int id, const int health, const int mana) \
    { return new Type(id, health, mana); }

/**
 * Number of player types
 */
constexpr size_t NUM_TYPES = 3;

// define the functions
PLAYER_CREATOR(Queen);
PLAYER_CREATOR(Witch);
PLAYER_CREATOR(Monk);

/**
 * The type of the functions for creating a player object
 */
typedef Player* (*player_constructor)(int id, int health, int mana);

/**
 * List of functions that can create a player object
 */
constexpr player_constructor PLAYER_CONSTRUCTORS[NUM_TYPES] {
    &makeQueen,
    &makeWitch,
    &makeMonk,
};

// RNG variables
std::default_random_engine rng;
std::uniform_int_distribution<int> playerTypeDist(0, NUM_TYPES - 1);
std::uniform_int_distribution<int> attrDist(10, 20);
auto playerType = std::bind(playerTypeDist, rng);
auto attr = std::bind(attrDist, rng);

Player* generateRandomPlayer(const int id)
{
    return PLAYER_CONSTRUCTORS[playerType()](id, attr(), attr());
}
