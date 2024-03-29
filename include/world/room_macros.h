#ifndef _ROOM_MACROS_H_
#define _ROOM_MACROS_H_

#include "prototypes/floor_beginning_room.h"

#include "prototypes/two_ninja_skeleton_room.h"
#include "prototypes/four_ancient_skeleton_room.h"
#include "prototypes/labyrinth_1_room.h"
#include "prototypes/labyrinth_2_room.h"
#include "prototypes/labyrinth_3_room.h"
#include "prototypes/dark_labyrinth_room.h"
#include "prototypes/ancient_room.h"
#include "prototypes/dumbbell_room.h"
#include "prototypes/symmetric_1_room.h"
#include "prototypes/symmetric_2_room.h"
#include "prototypes/corridors_room.h"
#include "prototypes/king_in_corridor_room.h"
#include "prototypes/pac_man_room.h"
#include "prototypes/pyramid_room.h"
#include "prototypes/spike_madness_room.h"

#include "prototypes/necromancer_boss_room.h"

#include "prototypes/floor_end_room.h"
#include "prototypes/end_game_room.h"
    
static void (*ROOM_PROTOTYPES_INIT_CALLBACKS[])(Room*, Entity*) = {
    &floorBeginningRoomInit,

    &twoNinjaSkeletonRoomInit,
    &fourAncientSkeletonRoomInit,
    &labyrinth1RoomInit,
    &labyrinth2RoomInit,
    &labyrinth3RoomInit,
    &darkLabyrinthRoomInit,
    &ancientRoomInit,
    &dumbbellRoomInit,
    &symmetric1RoomInit,
    &symmetric2RoomInit,
    &corridorsRoomInit,
    &kingInCorridorRoomInit,
    &pacmanRoomInit,
    &pyramidRoomInit,
    &spikeMadnessRoomInit,

    &necromancerBossRoomInit,

    &floorEndRoomInit,
    &endGameRoomInit
};

static void (*ROOM_PROTOTYPES_RENDER_CALLBACKS[])(Room*, void*) = {
    &floorBeginningRoomRender,

    &twoNinjaSkeletonRoomRender,
    &fourAncientSkeletonRoomRender,
    &labyrinth1RoomRender,
    &labyrinth2RoomRender,
    &labyrinth3RoomRender,
    &darkLabyrinthRoomRender,
    &ancientRoomRender,
    &dumbbellRoomRender,
    &symmetric1RoomRender,
    &symmetric2RoomRender,
    &corridorsRoomRender,
    &kingInCorridorRoomRender,
    &pacmanRoomRender,
    &pyramidRoomRender,
    &spikeMadnessRoomRender,

    &necromancerBossRoomRender,

    &floorEndRoomRender,
    &endGameRoomRender
};

static void (*ROOM_PROTOTYPES_UPDATE_CALLBACKS[])(void* _world, Room*, Entity*) = {
    &floorBeginningRoomUpdateCallback,

    &twoNinjaSkeletonRoomUpdateCallback,
    &fourAncientSkeletonRoomUpdateCallback,
    &labyrinth1RoomUpdateCallback,
    &labyrinth2RoomUpdateCallback,
    &labyrinth3RoomUpdateCallback,
    &darkLabyrinthRoomUpdateCallback,
    &ancientRoomUpdateCallback,
    &dumbbellRoomUpdateCallback,
    &symmetric1RoomUpdateCallback,
    &symmetric2RoomUpdateCallback,
    &corridorsRoomUpdateCallback,
    &kingInCorridorRoomUpdateCallback,
    &pacmanRoomUpdateCallback,
    &pyramidRoomUpdateCallback,
    &spikeMadnessRoomUpdateCallback,

    &necromancerBossRoomUpdateCallback,

    &floorEndRoomUpdateCallback,
    &endGameRoomUpdateCallback
};

#define _GET_RANDOM_ROOM_WITH_ENEMY_ getRandomInRange(1, 15)

#endif
