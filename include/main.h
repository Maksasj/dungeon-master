/**
 * Main
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * File that cotains some macros and includes needed for main.c file
*/

#ifndef _MAIN_H_
#define _MAIN_H_

#define MAIN_MENU_OPTION_COUNT 2

#include "utils/types.h"
#include "text/text.h"

#include "utils/memory.h"
#include "utils/gfx.h"
#include "world/world.h"
#include "sprite.h"
#include "buttons.h"
#include "utils/delay.h"
#include "entity/prototypes/player.h"
#include "sound/sound.h"
#include "timer.h"

#include "entity/entity.h"
#include "entity/prototypes/warrior.h"
#include "entity/prototypes/archer.h"
#include "entity/prototypes/wizard.h"

#include "entity/prototypes/projectile.h"

#include "../assets/generated/music/game_soundtrack_long.h"

#include "background.h"
#include "palette.h"
#include "../assets/generated/tile-map.h"
#include "../assets/generated/palettes.h"

#include "../assets/generated/menu.h"
#include "../assets/generated/intro.h"
#include "../assets/generated/sprites.h"

#include "item/item_macros.h"    

/* Enum that contains all available scenes in the game */
typedef enum ActiveScene {
    MAIN_MENU_SCENE,
    CHOOSE_SCENE,
    GAME_SCENE,
    SPLASH_SCENE,
    GAME_COMPLETE,
    GAME_FAILED
} ActiveScene;

/*
96 - Necromncer

112 - Iron armor front
120 - Iron armor back
128 - Iron armor side

136 - Golden armor front
144 - Golden armor back
152 - Golden armor side

160 - Diamoand armor front
168 - Diamoand armor back
176 - Diamoand armor side

256 - Short sword icon
264 - Dark claymore icon
272 - Ice sword icon

280 - Iron armor icon
288 - Golden armor icon
296 - DIamond armor icon

184 - Short sword front
192 - Short sword back
208 - Short sword side

208 - Claymore front
216 - Claymore back
224 - Claymore side

232 - Ice sword front
240 - Ice sword back
248 - Ice sword side

304 - Heart gem icon
312 - Mana bar
*/

/* Macro used to initialize all sprites for main menu */
#define _INIT_MAIN_MENU_SPRITES_                                                                            \
    Sprite* q1 = spriteInit(sprites, &next_sprite_index, 0, 0, SIZE_64_64, 0, 0, 128, 0);                   \
    Sprite* q2 = spriteInit(sprites, &next_sprite_index, 64, 0, SIZE_64_64, 0, 0, 256, 0);                  \
                                                                                                            \
    Sprite* q3 = spriteInit(sprites, &next_sprite_index, 128, 7, SIZE_64_32, 0, 0, 384, 0);                 \
    Sprite* q4 = spriteInit(sprites, &next_sprite_index, 192, 8, SIZE_32_32, 0, 0, 448, 0);                 \
                                                                                                            \
    Sprite* q5 = spriteInit(sprites, &next_sprite_index, 0, 64, SIZE_64_64, 0, 0, 512, 0);                  \
    Sprite* q6 = spriteInit(sprites, &next_sprite_index, 64, 64, SIZE_64_64, 0, 0, 640, 0);                 \
    Sprite* q7 = spriteInit(sprites, &next_sprite_index, 0, 128, SIZE_64_32, 0, 0, 768, 0);                 \
    Sprite* q8 = spriteInit(sprites, &next_sprite_index, 64, 128, SIZE_64_32, 0, 0, 832, 0);                \
    Sprite* buttonPlay = spriteInit(sprites, &next_sprite_index, 148, 59, SIZE_64_32, 0, 0, 0, 0);          \
    Sprite* buttonAbout = spriteInit(sprites, &next_sprite_index, 148, 100, SIZE_64_32, 0, 0, 960, 0);      \
                                                                                                            \
    Sprite* selectionArrow = spriteInit(sprites, &next_sprite_index, 130, 59, SIZE_32_32, 0, 0, 480, 0);    \

/* Macro used to render choose square on provided layer */
#define _RENDER_CHOOSE_SQUARE_(layer, X_OFFSET, Y_OFFSET)                       \
    {                                                                           \
    int i;                                                                      \
    int x;                                                                      \
    int y;                                                                      \
                                                                                \
    for(i = 1; i <= 4; ++i)                                                     \
        layer[X_OFFSET+ i + (Y_OFFSET * 32)] = 21 + 64 + 2;                     \
                                                                                \
    for(i = 1; i <= 4; ++i)                                                     \
        layer[X_OFFSET + i + ((Y_OFFSET + 5)* 32)] = 21 + 64 + 7;               \
                                                                                \
    for(x = 1; x <= 4; ++x)                                                     \
        for(y = 1; y <= 4; ++y)                                                 \
            layer[X_OFFSET + x + ((Y_OFFSET + y)* 32)] = 21 + 64 + 3;           \
                                                                                \
    for(y = 1; y <= 4; ++y)                                                     \
        layer[X_OFFSET + 5 + ((Y_OFFSET + y)* 32)] = 21 + 64 + 4;               \
                                                                                \
    for(y = 1; y <= 4; ++y)                                                     \
        layer[X_OFFSET + ((Y_OFFSET + y)* 32)] = 21 + 64 + 5;                   \
                                                                                \
    layer[X_OFFSET + (Y_OFFSET * 32)] = 21 + 64;                                \
    layer[X_OFFSET + 5 + (Y_OFFSET * 32)] = 21 + 64 + 1;                        \
    layer[X_OFFSET + ((Y_OFFSET + 5) * 32)] = 21 + 64 + 6;                      \
    layer[X_OFFSET + 5 + ((Y_OFFSET + 5) * 32)] = 21 + 64 + 8;                  \
    }                                                                           \

/* Macro used to render choose arrow facecd up */
#define _RENDER_ARROW_UP_(layer, x, y)              \
    layer[x + 1 + (y*32)] = 210;                    \
    layer[x + 2 + (y*32)] = 211;                    \
    layer[x + 1 + ((y + 1)*32)] = 242;              \
    layer[x + 2 + ((y + 1)*32)] = 243;              \

/* Macro used to render choose arrow face down */
#define _RENDER_ARROW_DOWN_(layer, x, y)            \
    layer[x + 1 + (y*32)] = 212;                    \
    layer[x + 2 + (y*32)] = 213;                    \
    layer[x + 1 + ((y + 1)*32)] = 244;              \
    layer[x + 2 + ((y + 1)*32)] = 245;              \

/* Macro used to clear specific tile on provided layer */
#define _CLEAR_TILE_(layer, x, y)                   \
    layer[x + 1 + (y*32)] = 0;                      \
    layer[x + 2 + (y*32)] = 0;                      \
    layer[x + 1 + ((y + 1)*32)] = 0;                \
    layer[x + 2 + ((y + 1)*32)] = 0;                \

/* Macro used to render size shadows on provided layer */
#define _RENDER_SIDE_SHADOW_(layer)                 \
    {                                               \
        int x;                                      \
        int y;                                      \
        for(x = 0; x < 30; ++x) {                   \
            for(y = 0; y < 30; ++y) {               \
                if(x == 0 || x == 29)               \
                    layer[x + y *32] = 0x17;        \
                                                    \
                if(x == 1 || x == 28)               \
                    layer[x + y *32] = 0x18;        \
                                                    \
                if(x == 2 || x == 27)               \
                    layer[x + y *32] = 0x19;        \
                                                    \
                if(x == 3 || x == 26)               \
                    layer[x + y *32] = 0x1A;        \
                                                    \
                if(x == 4 || x == 25)               \
                    layer[x + y *32] = 0x1B;        \
                                                    \
                if(x == 5 || x == 24)               \
                    layer[x + y *32] = 0x1C;        \
                                                    \
                if(x == 6 || x == 23)               \
                    layer[x + y *32] = 0x1D;        \
                                                    \
                if(x == 7 || x == 22)               \
                    layer[x + y *32] = 0x1E;        \
            }                                       \
        }                                           \
    }                                               \

/* Macro that hides some choose screen rendering */
#define _RENDER_CHOOSE_SCREEN_                      \
    _RENDER_SIDE_SHADOW_(lightLayer)                \
                                                    \
    {   int x;                                      \
        int y;                                      \
        for(x = 0; x < 17; ++x) {                   \
            lightLayer[7 + x + (2 * 32)] = 0xC1 + x;\
            lightLayer[7 + x + (3 * 32)] = 0xE1 + x;\
        }                                           \
        _RENDER_CHOOSE_SQUARE_(lightLayer, 4, 8);   \
        _RENDER_CHOOSE_SQUARE_(lightLayer, 12, 8);  \
        _RENDER_CHOOSE_SQUARE_(lightLayer, 20, 8);  \
    }                                               \

#define _ITEM_STAT_UI_RENDER_(layer, x, y)                      \
        layer[0 + x + (y + 0)*32] = 352;                        \
        layer[1 + x + (y + 0)*32] = 353;                        \
        layer[2 + x + (y + 0)*32] = 354;                        \
        layer[3 + x + (y + 0)*32] = 355;                        \
        layer[0 + x + (y + 1)*32] = 356;                        \
        layer[1 + x + (y + 1)*32] = 357;                        \
        layer[2 + x + (y + 1)*32] = 357;                        \
        layer[3 + x + (y + 1)*32] = 357;                        \
        layer[0 + x + (y + 2)*32] = 356;                        \
        layer[1 + x + (y + 2)*32] = 359;                        \
        layer[2 + x + (y + 2)*32] = 357;                        \
        layer[3 + x + (y + 2)*32] = 360;                        \
        layer[0 + x + (y + 3)*32] = 356;                        \
        layer[1 + x + (y + 3)*32] = 366;                        \
        layer[2 + x + (y + 3)*32] = 357;                        \
        layer[3 + x + (y + 3)*32] = 357;                        \
        layer[0 + x + (y + 4)*32] = 356;                        \
        layer[1 + x + (y + 4)*32] = 367;                        \
        layer[2 + x + (y + 4)*32] = 357;                        \
        layer[3 + x + (y + 4)*32] = 357;                        \
        layer[0 + x + (y + 5)*32] = 356;                        \
        layer[1 + x + (y + 5)*32] = 368;                        \
        layer[2 + x + (y + 5)*32] = 357;                        \
        layer[3 + x + (y + 5)*32] = 357;                        \
        layer[0 + x + (y + 6)*32] = 356;                        \
        layer[1 + x + (y + 6)*32] = 369;                        \
        layer[2 + x + (y + 6)*32] = 357;                        \
        layer[3 + x + (y + 6)*32] = 357;                        \
        layer[0 + x + (y + 7)*32] = 361;                        \
        layer[1 + x + (y + 7)*32] = 370;                        \
        layer[2 + x + (y + 7)*32] = 357;                        \
        layer[3 + x + (y + 7)*32] = 357;                        \
        layer[1 + x + (y + 8)*32] = 363;                        \
        layer[2 + x + (y + 8)*32] = 364;                        \
        layer[3 + x + (y + 8)*32] = 365;                        \
                                                                \
        layer[2 + x + (y + 3)*32] = 371;                        \
        layer[2 + x + (y + 4)*32] = 372;                        \
        layer[2 + x + (y + 5)*32] = 373;                        \
        layer[2 + x + (y + 6)*32] = 373;                        \
        layer[2 + x + (y + 7)*32] = 373;                        \
                                                                \
        layer[3 + x + (y + 3)*32] = 374;                        \
        layer[3 + x + (y + 4)*32] = 374;                        \
        layer[3 + x + (y + 5)*32] = 374;                        \
        layer[3 + x + (y + 6)*32] = 374;                        \
        layer[3 + x + (y + 7)*32] = 374;                        \

#endif
