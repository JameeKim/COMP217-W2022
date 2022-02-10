/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #4 (due Sun. Feb. 13, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include "RoyalGun.h"

RoyalGun::RoyalGun(
    const int maxAmmo,
    const int currentAmmo,
    const int damage)
    : Weapon("Royal Gun", maxAmmo, currentAmmo, damage)
{
}
