/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #1 (Wed. Jan. 12, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

// Returns the default player health
int playerDefaultHealth = 100;

// Returns the actual player health
int getPlayerHealth() {
  return 80;
}

namespace player {
  // Returns if the player is attacking
  bool isAttacking() {
    return false;
  }
}

namespace enemy {
  // Returns if the enemy is attacking
  bool isAttacking() {
    return true;
  }
}
