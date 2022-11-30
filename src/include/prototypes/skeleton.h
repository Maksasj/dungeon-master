#ifndef _SKELETON_H_
#define _SKELETON_H_

#include "../world/room.h"
#include "../world.h"
#include "../entity/entity.h"
#include "../sound.h"

#define _RANGE_ 4
#define _ROOM_WORLD_LENGTH_ 12
#define _ROOM_WORLD_WIDTH_ 7

void skeleton_update(Entity* _self, World* _world, Room* _room);

void skeleton_kill(Entity* _self);

#endif
