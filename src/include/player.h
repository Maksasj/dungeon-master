#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "buttons.h"
#include "sprite.h"
#include "types.h"
#include "entity/entity.h"
#include "world/room.h"
#include "world.h"
#include "logger.h"

#define _ATTACK_OFFSET_ 8

typedef struct PlayerSpecData {
    Sprite* armor;
    Sprite* weapon;

    Sprite* sprites;
    i32* next_sprite_index;

    Item hand_slot;
    Item armor_slot;
} PlayerSpecData;

typedef struct PlayerUI {
    Sprite* health[3];
    Sprite* manaBar;
} PlayerUI;

void initPlayerUI(PlayerUI* _playerUI, Sprite* _sprites, i32* _next_sprite_index);

void initPlayerSpec(Sprite* _sprites, i32* _next_sprite_index, Entity* _entity, PlayerSpecData* _pspec);

void updatePlayerSpec(PlayerSpecData* _pspec, Entity *_entity);

void playerAttack(Entity* _self, Room* _active_room);

i32 playerCalculateDamage(Entity* _self);

void killPlayer(Entity* _self);

void player_update(Entity* _self, World* _world, Room* _room);

#endif
