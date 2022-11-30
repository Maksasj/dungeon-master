#include "../include/prototypes/skeleton.h"

void skeleton_update(Entity* _self, World* _world, Room* _room) {
    ivec2 world_position = screenToGridPosition(_self->position);

    i8 direction = _world->grid.vertices[world_position.x][world_position.y];
    i32 distance_to_player = _world->grid.distance_to_player[world_position.x][world_position.y];

    switch (direction)
    {
        case 'u': //Up
            if (distance_to_player > _RANGE_) {
                _self->position.y += 1;
            } else if (distance_to_player < _RANGE_) {
                if (world_position.y - 1 >= 0) {
                    _self->position.y -= 1;
                } else if (world_position.x + 1 <= _ROOM_WORLD_LENGTH_){
                    _self->position.x += 1;
                }
            }
            break;
        case 'r': //Right
            if (distance_to_player > _RANGE_) {
                _self->position.x += 1;
            } else if (distance_to_player < _RANGE_) {
                if (world_position.x - 1 >= 0) {
                    _self->position.x -= 1;
                } else if (world_position.y - 1 >= 0) {
                    _self->position.y -= 1;
                }
            }
            break;
        case 'd': //Down
            if (distance_to_player > _RANGE_) {
                _self->position.y -= 1;
            } else if (distance_to_player < _RANGE_) {
                if (world_position.y + 1 <= _ROOM_WORLD_WIDTH_) {
                    _self->position.y += 1;
                } else if (world_position.x - 1 >= 0){
                    _self->position.x -= 1;
                }
            }
            break;
        case 'l': //Left
            if (distance_to_player > _RANGE_) {
                _self->position.x -= 1;
            } else if (distance_to_player < _RANGE_) {
                if (world_position.x + 1 <= _ROOM_WORLD_LENGTH_) {
                    _self->position.x += 1;
                } else if (world_position.y + 1 <= _ROOM_WORLD_WIDTH_) {
                    _self->position.y += 1;   
                }
            }
            break;
        default:
            break;
    }

    /*
    _self->position.x += _self->vel.x;
    _self->position.y += _self->vel.y;

    _self->vel.x = 0;
    _self->vel.y = 0;
    */
}

void skeleton_kill(Entity* _self) {
    notePlay(NOTE_C, 1);
}
