#ifndef _MAIN_H_
#define _MAIN_H_

#define MAIN_MENU_OPTION_COUNT 2

#include "types.h"
#include "text/text.h"

#include "memory.h"
#include "gfx.h"
#include "world.h"
#include "sprite.h"
#include "buttons.h"
#include "delay.h"
#include "player.h"
#include "interruption.h"
#include "sound.h"

#include "entity/entity.h"

#include "../../assets/generated/music/game_soundtrack_long.h"

#include "background.h"

#include "../../assets/generated/menu.h"
#include "../../assets/generated/sprites.h"

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

#define _INIT_MAIN_MENU_SPRITES_                                                                        \
    Sprite* q1 = spriteInit(sprites, &next_sprite_index, 0, 0, SIZE_64_64, 0, 0, 128, 0);               \
    Sprite* q2 = spriteInit(sprites, &next_sprite_index, 64, 0, SIZE_64_64, 0, 0, 256, 0);              \
                                                                                                        \
    Sprite* q3 = spriteInit(sprites, &next_sprite_index, 128, 7, SIZE_64_32, 0, 0, 384, 0);             \
    Sprite* q4 = spriteInit(sprites, &next_sprite_index, 192, 8, SIZE_32_32, 0, 0, 448, 0);             \
                                                                                                        \
    Sprite* q5 = spriteInit(sprites, &next_sprite_index, 0, 64, SIZE_64_64, 0, 0, 512, 0);              \
    Sprite* q6 = spriteInit(sprites, &next_sprite_index, 64, 64, SIZE_64_64, 0, 0, 640, 0);             \
    Sprite* q7 = spriteInit(sprites, &next_sprite_index, 0, 128, SIZE_64_32, 0, 0, 768, 0);             \
    Sprite* q8 = spriteInit(sprites, &next_sprite_index, 64, 128, SIZE_64_32, 0, 0, 832, 0);            \
    Sprite* buttonPlay = spriteInit(sprites, &next_sprite_index, 148, 59, SIZE_64_32, 0, 0, 0, 0);      \
    Sprite* buttonAbout = spriteInit(sprites, &next_sprite_index, 148, 100, SIZE_64_32, 0, 0, 64, 0);   \
                                                                                                        \
    Sprite* selectionArrow = spriteInit(sprites, &next_sprite_index, 130, 59, SIZE_32_32, 0, 0, 480, 0);\


#define _INIT_MAIN_MENU_BACKGROUND_ for(i = 0; i < 15; ++i) { for(j = 0; j < 10; ++j) { MAP[i*2 + j*2 * 32] = 0x0015; MAP[i*2 + j*2 * 32 + 1] = 0x0016; MAP[i*2 + j*2 * 32 + 32] = 0x0035; MAP[i*2 + j*2 * 32 + 33] = 0x0036; } }

#endif