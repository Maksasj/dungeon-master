#ifndef _ENTITY_MACROS_H_
#define _ENTITY_MACROS_H_

#include "entity.h"

#include "prototypes/skeleton_ninja.h"
#include "prototypes/skeleton_king.h"
#include "prototypes/skeleton_ancient.h"
#include "prototypes/necromancer.h"

#define _SKELETON_NINJA_ENTITY_(X, Y)                           \
    entityReload((Entity){                                      \
        .position = newIVec2(X << POSITION_FIXED_SCALAR, Y << POSITION_FIXED_SCALAR),                   \
                                                                \
        .layer = ENEMY,                                         \
        .base_stats = stats(1, 3, 0, 0, 0),                     \
        .sprite_offset = 24,                                    \
        .update_callback = &skeletonNinjaUpdate,                \
        .on_collision_enter = &checkCollision,                  \
        .die_callback = &skeletonNinjaKill,                     \
        .attack_callback = &skeletonNinjaCalculateDamage,       \
        .dodge_callback = &skeletonNinjaTryDodge                \
    })                                                          \

#define _SKELETON_KING_ENTITY_(X, Y)                            \
    entityReload((Entity){                                      \
        .position = newIVec2(X << POSITION_FIXED_SCALAR, Y << POSITION_FIXED_SCALAR),                   \
                                                                \
        .layer = ENEMY,                                         \
        .base_stats = stats(3, 0, 0, 1, 0),                     \
        .sprite_offset = 48,                                    \
        .update_callback = &skeletonKingUpdate,                 \
        .on_collision_enter = &checkCollision,                  \
        .die_callback = &skeletonKingKill,                      \
        .attack_callback = &skeletonKingCalculateDamage,        \
        .dodge_callback = &skeletonKingTryDodge                 \
    })                                                          \

#define _SKELETON_ANCIENT_ENTITY_(X, Y)                         \
    entityReload((Entity){                                      \
        .position = newIVec2(X << POSITION_FIXED_SCALAR, Y << POSITION_FIXED_SCALAR),                   \
                                                                \
        .layer = ENEMY,                                         \
        .base_stats = stats(1, 1, 0, 0, 0),                     \
        .sprite_offset = 72,                                    \
        .update_callback = &skeletonAncientUpdate,              \
        .on_collision_enter = &checkCollision,                  \
        .die_callback = &skeletonAncientKill,                   \
        .attack_callback = &skeletonAncientCalculateDamage,     \
        .dodge_callback = &skeletonAncientTryDodge              \
    })                                                          \

#define _NECROMANCER_ENTITY_(X, Y)                              \
    entityReload((Entity){                                      \
        .position = newIVec2(X << POSITION_FIXED_SCALAR, Y << POSITION_FIXED_SCALAR),                   \
                                                                \
        .layer = ENEMY,                                         \
        .base_stats = stats(2, 1, 1, 0, 0),                     \
        .sprite_offset = 96,                                    \
        .update_callback = &necromancerUpdate,                  \
        .on_collision_enter = &checkCollision,                  \
        .die_callback = &necromancerKill,                       \
        .attack_callback = &necromancerCalculateDamage,         \
        .dodge_callback = &necromancerTryDodge                  \
    })                                                          \

#endif
