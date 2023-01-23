/**
 * warrior
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * warrior entity
*/

#ifndef _WARRIOR_H_
#define _WARRIOR_H_

#include "../entity.h"

#include "player.h"

#include "../../world/room.h"

#include "../../utils/types.h"

/* Mellee attack range */
#define _ATTACK_OFFSET_ 8

/**
 * Calculates damage by looking at characteristics 
 * 
 * @param _warrior      existing warrior
 * 
 * @return Calculated damage
*/
i32 warriorCalculateDamage(Entity* _warrior);

#endif
