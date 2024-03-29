#include "../../../include/entity/prototypes/skeleton_ancient.h"

const static i32 GRID_LENGTH = 12;
const static i32 GRID_HEIGHT = 7;
static const u32 FIELD_OF_VIEW_RANGE = 7;

void skeletonAncientUpdate(Entity* _self, World* _world, Room* _room) {
    ivec2 world_position = screenToWorldPosition(_self->position);

    if (!_self->saw_the_target) {
        if (_world->grid.distance_to_player[world_position.x][world_position.y] > FIELD_OF_VIEW_RANGE) {
            return;
        } else if (_world->grid.distance_to_player[world_position.x][world_position.y] <= FIELD_OF_VIEW_RANGE && _world->grid.distance_to_player[world_position.x][world_position.y] != 0){
            _self->saw_the_target = 1;
        }
    }

    i8 direction = _world->grid.vertices[world_position.x][world_position.y];
    
    _self->vel.x = _DIV2_(_self->vel.x);
    _self->vel.y = _DIV2_(_self->vel.y);

    switch (direction)
    {
        case 'u': { //Up
            _self->vel.y += VELOCITY_CONSTANT;
            _self->facing = DOWN;
            break;
        }
        case 'r': { //Right
            _self->vel.x += VELOCITY_CONSTANT;
            _self->facing = RIGHT;
            break;
        }
        case 'd': { //Down
            _self->vel.y -= VELOCITY_CONSTANT;
            _self->facing = UP;
            break;
        }
        case 'l': { //Left
            _self->vel.x -= VELOCITY_CONSTANT;
            _self->facing = LEFT;
            break;
        }
        case '#': {
            switch (_self->facing) {
                case UP: {
                    _self->vel.y = -10;
                    break;
                }
                case RIGHT: {
                    _self->vel.x = 10;
                    break;
                }
                case DOWN: {
                    _self->vel.y = 10;
                    break;
                }
                case LEFT: {
                    _self->vel.x = -10;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }

    switch (_self->facing) {
        case DOWN: {
            spriteSetOffset(_self->sprite, 88);
            break;
        }
        case RIGHT: {
            spriteSetOffset(_self->sprite, 72);
            spriteSetHorizontalFlip(_self->sprite, 1);
            break;
        }
        case UP: {
            spriteSetOffset(_self->sprite, 80);
            break;
        }
        case LEFT: {
            spriteSetOffset(_self->sprite, 72);
            spriteSetHorizontalFlip(_self->sprite, 0);
            break;
        }
        default:
            break;
    }

    if (world_position.x < 0) {
        _self->vel.x = 10;
    } else if (world_position.x > GRID_LENGTH) {
        _self->vel.x = -10;
    } else if (world_position.y < 0) {
        _self->vel.y = 10;
    } else if (world_position.y > GRID_HEIGHT) {
        _self->vel.y = -10;
    }

    _self->position.x += _self->vel.x;
    _self->position.y += _self->vel.y;
}

void skeletonAncientKill(Entity* _self) {
    notePlay(NOTE_C, 1);
}

i32 skeletonAncientCalculateDamage(Entity* _self) {
    i32 strenght = _self->base_stats.strength;
    
    if (strenght < 0) {
        strenght = 0;
    }
    
    return 1 + strenght;
}

i32 skeletonAncientTryDodge(Entity* _self) {
    u32 random_number = random((u32)_self->position.x * (u32)_self->position.y) % 101;

    if (random_number < _DODGE_CHANCE_FROM_AGILITY_ * _self->base_stats.agility) {
        return 1;
    }

    return 0;
}
