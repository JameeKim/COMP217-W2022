/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "PlayerFactory.h"

#include <random>

#include "Monk.h"
#include "Player.h"
#include "Queen.h"
#include "Witch.h"
#include "Weapon/Broom.h"
#include "Weapon/EnergyOrb.h"
#include "Weapon/LaserGun.h"
#include "Weapon/MagicWand.h"
#include "Weapon/RoyalGun.h"
#include "Weapon/RustySword.h"

/**
 * Generate a random integer in the range of [min, max) using a randomly
 * generated float value in the range of [0, 1)
 */
int randomInt(const int min, const int max)
{
    static std::random_device r;
    static std::default_random_engine rng(r());
    static std::uniform_real_distribution<float> random;
    return static_cast<int>(random(rng) * (max - min)) + min;
}

/**
 * The type of the functions for adding a weapon to a player
 */
typedef void (*weapon_appender)(Player* player);

/**
 * The type of the functions for creating a player object
 */
typedef Player* (*player_factory)(int id, int health, int mana);

/**
 * Macro for creating a compile-time constant list along with its size
 */
#define CREATE_LIST(Type, Name, ...) \
    constexpr Type Name[] { __VA_ARGS__ }; \
    constexpr int Name##_SIZE = static_cast<int>(sizeof Name / sizeof Type);

/**
 * Macro for creating functions that add a weapon to a player
 */
#define WEAPON_CREATOR(WType, MaxAmmo, Damage) \
    void add##WType(Player* player) \
    { \
        player->addWeapon( \
            new WType(MaxAmmo, randomInt(0, MaxAmmo + 1), Damage) \
        ); \
    }

/**
 * Macro for creating functions that call constructors of Player subclasses
 */
#define PLAYER_CREATOR(PType, ...) \
    CREATE_LIST(weapon_appender, PType##_WEAPONS, __VA_ARGS__); \
    Player* make##PType(const int id, const int health, const int mana) \
    { \
        PType* player = new PType(id, health, mana); \
        /* Add 0, 1, 2, or 3 weapons */ \
        int numWeapons = randomInt(0, 4); \
        while (numWeapons > 0) { \
            int weaponIdx = randomInt(0, PType##_WEAPONS_SIZE); \
            PType##_WEAPONS[weaponIdx](player); \
            numWeapons--; \
        } \
        return player; \
    }

// define weapons
WEAPON_CREATOR(RustySword, 2, 1);
WEAPON_CREATOR(RoyalGun, 6, 4);
WEAPON_CREATOR(MagicWand, 4, 5);
WEAPON_CREATOR(Broom, 2, 7);
WEAPON_CREATOR(EnergyOrb, 1, 8);
WEAPON_CREATOR(LaserGun, 20, 3);

// define player types with available weapons
// items are repeated to provide better probability for each weapon type
PLAYER_CREATOR(Queen, &addRustySword, &addRoyalGun, &addRoyalGun, &addRoyalGun);
PLAYER_CREATOR(Witch, &addRustySword, &addMagicWand, &addBroom);
PLAYER_CREATOR(Monk, &addRustySword, &addEnergyOrb, &addLaserGun);

/**
 * List of functions that can create a player object
 */
CREATE_LIST(player_factory, PLAYER_TYPES, &makeQueen, &makeWitch, &makeMonk);

Player* generateRandomPlayer(const int id)
{
    const player_factory cons = PLAYER_TYPES[randomInt(0, PLAYER_TYPES_SIZE)];
    return cons(id, randomInt(10, 21), randomInt(10, 21));
}
