#ifndef _FLOOR_BEGINNING_ROOM_H_
#define _FLOOR_BEGINNING_ROOM_H_

#include "../room.h"
#include "../tile.h"

void floorBeginningRoomInit(Room* _self, Entity* _player);

void floorBeginningRoomRender(Room* _self, void* _world);

void floorBeginningRoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
