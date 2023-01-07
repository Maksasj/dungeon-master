/**
 * Light
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * File that cotains some macros and function for purpose of rendering light in the game
*/

#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "utils/types.h"

/* All build in light tile indexes
0x17 - Dark
0x18 - Dark by lighter
0x19 - Grid
0x1A - Pluses
0x1B - Dots
0x1C - Pluses inverse
0x1D - A fiew dots
0x1E - Fiewest
*/

/**
 * Set value to all light level tiles
 * 
 * @param   _light  New value for all light tiles
*/
void setLightLayer(i32 _light);

/* Macro used to render shadow circle */
#define SHADOW_BULB(dest, x , y)             \
    dest[(x - 1) + (32*(y - 1))] = 0x17;     \
    dest[(x + 2) + (32*(y - 1))] = 0x17;     \
    dest[(x + 2) + (32*(y + 2))] = 0x17;     \
    dest[(x - 1) + (32*(y + 2))] = 0x17;     \
    dest[(x + 0) + (32*(y + 0))] = 0x17;     \
    dest[(x + 1) + (32*(y + 0))] = 0x17;     \
    dest[(x + 1) + (32*(y + 1))] = 0x17;     \
    dest[(x + 0) + (32*(y + 1))] = 0x17;     \
    dest[(x - 0) + (32*(y - 1))] = 0x17;     \
    dest[(x + 1) + (32*(y - 1))] = 0x17;     \
    dest[(x - 1) + (32*(y - 0))] = 0x17;     \
    dest[(x - 1) + (32*(y + 1))] = 0x17;     \
    dest[(x + 2) + (32*(y + 0))] = 0x17;     \
    dest[(x + 2) + (32*(y + 1))] = 0x17;     \
    dest[(x + 0) + (32*(y + 2))] = 0x17;     \
    dest[(x + 1) + (32*(y + 2))] = 0x17;     \
    dest[(x - 0) + (32*(y - 2))] = 0x17;     \
    dest[(x - 0) + (32*(y - 3))] = 0x17;     \
    dest[(x - 0) + (32*(y - 4))] = 0x17;     \
    dest[(x - 0) + (32*(y - 5))] = 0x17;     \
    dest[(x + 1) + (32*(y - 2))] = 0x17;     \
    dest[(x + 1) + (32*(y - 3))] = 0x17;     \
    dest[(x + 1) + (32*(y - 4))] = 0x17;     \
    dest[(x + 1) + (32*(y - 5))] = 0x17;     \
    dest[(x - 2) + (32*(y + 0))] = 0x17;     \
    dest[(x - 3) + (32*(y + 0))] = 0x17;     \
    dest[(x - 4) + (32*(y + 0))] = 0x17;     \
    dest[(x - 5) + (32*(y + 0))] = 0x17;     \
    dest[(x - 2) + (32*(y + 1))] = 0x17;     \
    dest[(x - 3) + (32*(y + 1))] = 0x17;     \
    dest[(x - 4) + (32*(y + 1))] = 0x17;     \
    dest[(x - 5) + (32*(y + 1))] = 0x17;     \
    dest[(x + 3) + (32*(y + 1))] = 0x17;     \
    dest[(x + 4) + (32*(y + 1))] = 0x17;     \
    dest[(x + 5) + (32*(y + 1))] = 0x17;     \
    dest[(x + 6) + (32*(y + 1))] = 0x17;     \
    dest[(x + 3) + (32*(y + 0))] = 0x17;     \
    dest[(x + 4) + (32*(y + 0))] = 0x17;     \
    dest[(x + 5) + (32*(y + 0))] = 0x17;     \
    dest[(x + 6) + (32*(y + 0))] = 0x17;     \
    dest[(x + 1) + (32*(y + 3))] = 0x17;     \
    dest[(x + 1) + (32*(y + 4))] = 0x17;     \
    dest[(x + 1) + (32*(y + 5))] = 0x17;     \
    dest[(x + 1) + (32*(y + 6))] = 0x17;     \
    dest[(x + 0) + (32*(y + 3))] = 0x17;     \
    dest[(x + 0) + (32*(y + 4))] = 0x17;     \
    dest[(x + 0) + (32*(y + 5))] = 0x17;     \
    dest[(x + 0) + (32*(y + 6))] = 0x17;     \
    dest[(x + 2) + (32*(y - 1))] = 0x17;     \
    dest[(x + 2) + (32*(y - 2))] = 0x17;     \
    dest[(x + 2) + (32*(y - 3))] = 0x17;     \
    dest[(x + 2) + (32*(y - 4))] = 0x17;     \
    dest[(x - 1) + (32*(y - 1))] = 0x17;     \
    dest[(x - 1) + (32*(y - 2))] = 0x17;     \
    dest[(x - 1) + (32*(y - 3))] = 0x17;     \
    dest[(x - 1) + (32*(y - 4))] = 0x17;     \
    dest[(x - 1) + (32*(y + 2))] = 0x17;     \
    dest[(x - 2) + (32*(y + 2))] = 0x17;     \
    dest[(x - 3) + (32*(y + 2))] = 0x17;     \
    dest[(x - 4) + (32*(y + 2))] = 0x17;     \
    dest[(x - 1) + (32*(y - 1))] = 0x17;     \
    dest[(x - 2) + (32*(y - 1))] = 0x17;     \
    dest[(x - 3) + (32*(y - 1))] = 0x17;     \
    dest[(x - 4) + (32*(y - 1))] = 0x17;     \
    dest[(x + 2) + (32*(y + 2))] = 0x17;     \
    dest[(x + 3) + (32*(y + 2))] = 0x17;     \
    dest[(x + 4) + (32*(y + 2))] = 0x17;     \
    dest[(x + 5) + (32*(y + 2))] = 0x17;     \
    dest[(x + 2) + (32*(y - 1))] = 0x17;     \
    dest[(x + 3) + (32*(y - 1))] = 0x17;     \
    dest[(x + 4) + (32*(y - 1))] = 0x17;     \
    dest[(x + 5) + (32*(y - 1))] = 0x17;     \
    dest[(x + 2) + (32*(y + 2))] = 0x17;     \
    dest[(x + 2) + (32*(y + 3))] = 0x17;     \
    dest[(x + 2) + (32*(y + 4))] = 0x17;     \
    dest[(x + 2) + (32*(y + 5))] = 0x17;     \
    dest[(x - 1) + (32*(y + 2))] = 0x17;     \
    dest[(x - 1) + (32*(y + 3))] = 0x17;     \
    dest[(x - 1) + (32*(y + 4))] = 0x17;     \
    dest[(x - 1) + (32*(y + 5))] = 0x17;     \
    dest[(x - 2) + (32*(y - 2))] = 0x17;     \
    dest[(x - 3) + (32*(y - 2))] = 0x17;     \
    dest[(x - 2) + (32*(y - 3))] = 0x17;     \
    dest[(x - 4) + (32*(y - 2))] = 0x17;     \
    dest[(x - 2) + (32*(y - 4))] = 0x17;     \
    dest[(x - 3) + (32*(y - 3))] = 0x17;     \
    dest[(x - 4) + (32*(y - 3))] = 0x17;     \
    dest[(x - 3) + (32*(y - 4))] = 0x17;     \
    dest[(x + 3) + (32*(y + 3))] = 0x17;     \
    dest[(x + 3) + (32*(y + 4))] = 0x17;     \
    dest[(x + 4) + (32*(y + 3))] = 0x17;     \
    dest[(x + 3) + (32*(y + 5))] = 0x17;     \
    dest[(x + 5) + (32*(y + 3))] = 0x17;     \
    dest[(x + 4) + (32*(y + 4))] = 0x17;     \
    dest[(x + 4) + (32*(y + 5))] = 0x17;     \
    dest[(x + 5) + (32*(y + 4))] = 0x17;     \
    dest[(x - 2) + (32*(y + 3))] = 0x17;     \
    dest[(x - 3) + (32*(y + 4))] = 0x17;     \
    dest[(x - 2) + (32*(y + 4))] = 0x17;     \
    dest[(x - 3) + (32*(y + 3))] = 0x17;     \
    dest[(x - 4) + (32*(y + 3))] = 0x17;     \
    dest[(x - 4) + (32*(y + 4))] = 0x17;     \
    dest[(x - 3) + (32*(y + 5))] = 0x17;     \
    dest[(x - 2) + (32*(y + 5))] = 0x17;     \
    dest[(x + 3) + (32*(y - 2))] = 0x17;     \
    dest[(x + 4) + (32*(y - 3))] = 0x17;     \
    dest[(x + 4) + (32*(y - 2))] = 0x17;     \
    dest[(x + 3) + (32*(y - 3))] = 0x17;     \
    dest[(x + 3) + (32*(y - 4))] = 0x17;     \
    dest[(x + 4) + (32*(y - 4))] = 0x17;     \
    dest[(x + 5) + (32*(y - 3))] = 0x17;     \
    dest[(x + 5) + (32*(y - 2))] = 0x17;     \

/* Macro used to render static light circle */
#define RENDER_LIGHT_BULB(dest, x, y)        \
    dest[(x - 1) + (32*(y - 1))] = 0x1E;     \
    dest[(x + 2) + (32*(y - 1))] = 0x1E;     \
    dest[(x + 2) + (32*(y + 2))] = 0x1E;     \
    dest[(x - 1) + (32*(y + 2))] = 0x1E;     \
    dest[(x + 0) + (32*(y + 0))] = 0x1F;     \
    dest[(x + 1) + (32*(y + 0))] = 0x1F;     \
    dest[(x + 1) + (32*(y + 1))] = 0x1F;     \
    dest[(x + 0) + (32*(y + 1))] = 0x1F;     \
    dest[(x - 0) + (32*(y - 1))] = 0x1F;     \
    dest[(x + 1) + (32*(y - 1))] = 0x1F;     \
    dest[(x - 1) + (32*(y - 0))] = 0x1F;     \
    dest[(x - 1) + (32*(y + 1))] = 0x1F;     \
    dest[(x + 2) + (32*(y + 0))] = 0x1F;     \
    dest[(x + 2) + (32*(y + 1))] = 0x1F;     \
    dest[(x + 0) + (32*(y + 2))] = 0x1F;     \
    dest[(x + 1) + (32*(y + 2))] = 0x1F;     \
    dest[(x - 0) + (32*(y - 2))] = 0x1E;     \
    dest[(x - 0) + (32*(y - 3))] = 0x1D;     \
    dest[(x - 0) + (32*(y - 4))] = 0x19;     \
    dest[(x - 0) + (32*(y - 5))] = 0x18;     \
    dest[(x + 1) + (32*(y - 2))] = 0x1E;     \
    dest[(x + 1) + (32*(y - 3))] = 0x1D;     \
    dest[(x + 1) + (32*(y - 4))] = 0x19;     \
    dest[(x + 1) + (32*(y - 5))] = 0x18;     \
    dest[(x - 2) + (32*(y + 0))] = 0x1E;     \
    dest[(x - 3) + (32*(y + 0))] = 0x1D;     \
    dest[(x - 4) + (32*(y + 0))] = 0x19;     \
    dest[(x - 5) + (32*(y + 0))] = 0x18;     \
    dest[(x - 2) + (32*(y + 1))] = 0x1E;     \
    dest[(x - 3) + (32*(y + 1))] = 0x1D;     \
    dest[(x - 4) + (32*(y + 1))] = 0x19;     \
    dest[(x - 5) + (32*(y + 1))] = 0x18;     \
    dest[(x + 3) + (32*(y + 1))] = 0x1E;     \
    dest[(x + 4) + (32*(y + 1))] = 0x1D;     \
    dest[(x + 5) + (32*(y + 1))] = 0x19;     \
    dest[(x + 6) + (32*(y + 1))] = 0x18;     \
    dest[(x + 3) + (32*(y + 0))] = 0x1E;     \
    dest[(x + 4) + (32*(y + 0))] = 0x1D;     \
    dest[(x + 5) + (32*(y + 0))] = 0x19;     \
    dest[(x + 6) + (32*(y + 0))] = 0x18;     \
    dest[(x + 1) + (32*(y + 3))] = 0x1E;     \
    dest[(x + 1) + (32*(y + 4))] = 0x1D;     \
    dest[(x + 1) + (32*(y + 5))] = 0x19;     \
    dest[(x + 1) + (32*(y + 6))] = 0x18;     \
    dest[(x + 0) + (32*(y + 3))] = 0x1E;     \
    dest[(x + 0) + (32*(y + 4))] = 0x1D;     \
    dest[(x + 0) + (32*(y + 5))] = 0x19;     \
    dest[(x + 0) + (32*(y + 6))] = 0x18;     \
    dest[(x + 2) + (32*(y - 1))] = 0x1E;     \
    dest[(x + 2) + (32*(y - 2))] = 0x1D;     \
    dest[(x + 2) + (32*(y - 3))] = 0x1B;     \
    dest[(x + 2) + (32*(y - 4))] = 0x18;     \
    dest[(x - 1) + (32*(y - 1))] = 0x1E;     \
    dest[(x - 1) + (32*(y - 2))] = 0x1D;     \
    dest[(x - 1) + (32*(y - 3))] = 0x1B;     \
    dest[(x - 1) + (32*(y - 4))] = 0x18;     \
    dest[(x - 1) + (32*(y + 2))] = 0x1E;     \
    dest[(x - 2) + (32*(y + 2))] = 0x1D;     \
    dest[(x - 3) + (32*(y + 2))] = 0x1B;     \
    dest[(x - 4) + (32*(y + 2))] = 0x18;     \
    dest[(x - 1) + (32*(y - 1))] = 0x1E;     \
    dest[(x - 2) + (32*(y - 1))] = 0x1D;     \
    dest[(x - 3) + (32*(y - 1))] = 0x1B;     \
    dest[(x - 4) + (32*(y - 1))] = 0x18;     \
    dest[(x + 2) + (32*(y + 2))] = 0x1E;     \
    dest[(x + 3) + (32*(y + 2))] = 0x1D;     \
    dest[(x + 4) + (32*(y + 2))] = 0x1B;     \
    dest[(x + 5) + (32*(y + 2))] = 0x18;     \
    dest[(x + 2) + (32*(y - 1))] = 0x1E;     \
    dest[(x + 3) + (32*(y - 1))] = 0x1D;     \
    dest[(x + 4) + (32*(y - 1))] = 0x1B;     \
    dest[(x + 5) + (32*(y - 1))] = 0x18;     \
    dest[(x + 2) + (32*(y + 2))] = 0x1E;     \
    dest[(x + 2) + (32*(y + 3))] = 0x1D;     \
    dest[(x + 2) + (32*(y + 4))] = 0x1B;     \
    dest[(x + 2) + (32*(y + 5))] = 0x18;     \
    dest[(x - 1) + (32*(y + 2))] = 0x1E;     \
    dest[(x - 1) + (32*(y + 3))] = 0x1D;     \
    dest[(x - 1) + (32*(y + 4))] = 0x1B;     \
    dest[(x - 1) + (32*(y + 5))] = 0x18;     \
    dest[(x - 2) + (32*(y - 2))] = 0x1C;     \
    dest[(x - 3) + (32*(y - 2))] = 0x1A;     \
    dest[(x - 2) + (32*(y - 3))] = 0x1A;     \
    dest[(x - 4) + (32*(y - 2))] = 0x18;     \
    dest[(x - 2) + (32*(y - 4))] = 0x18;     \
    dest[(x - 3) + (32*(y - 3))] = 0x19;     \
    dest[(x - 4) + (32*(y - 3))] = 0x18;     \
    dest[(x - 3) + (32*(y - 4))] = 0x18;     \
    dest[(x + 3) + (32*(y + 3))] = 0x1C;     \
    dest[(x + 3) + (32*(y + 4))] = 0x1A;     \
    dest[(x + 4) + (32*(y + 3))] = 0x1A;     \
    dest[(x + 3) + (32*(y + 5))] = 0x18;     \
    dest[(x + 5) + (32*(y + 3))] = 0x18;     \
    dest[(x + 4) + (32*(y + 4))] = 0x19;     \
    dest[(x + 4) + (32*(y + 5))] = 0x18;     \
    dest[(x + 5) + (32*(y + 4))] = 0x18;     \
    dest[(x - 2) + (32*(y + 3))] = 0x1C;     \
    dest[(x - 3) + (32*(y + 4))] = 0x19;     \
    dest[(x - 2) + (32*(y + 4))] = 0x1A;     \
    dest[(x - 3) + (32*(y + 3))] = 0x1A;     \
    dest[(x - 4) + (32*(y + 3))] = 0x18;     \
    dest[(x - 4) + (32*(y + 4))] = 0x18;     \
    dest[(x - 3) + (32*(y + 5))] = 0x18;     \
    dest[(x - 2) + (32*(y + 5))] = 0x18;     \
    dest[(x + 3) + (32*(y - 2))] = 0x1C;     \
    dest[(x + 4) + (32*(y - 3))] = 0x19;     \
    dest[(x + 4) + (32*(y - 2))] = 0x1A;     \
    dest[(x + 3) + (32*(y - 3))] = 0x1A;     \
    dest[(x + 3) + (32*(y - 4))] = 0x18;     \
    dest[(x + 4) + (32*(y - 4))] = 0x18;     \
    dest[(x + 5) + (32*(y - 3))] = 0x18;     \
    dest[(x + 5) + (32*(y - 2))] = 0x18;     \

/* Macro used to render dynamic light circle */
#define RENDER_DYNAMIC_LIGHT_BULB(dest, x, y)                                                                         \
    dest[(x - 1) + (32*(y - 1))] = ( 0x1E > dest[(x - 1) + (32*(y - 1))] ) ? 0x1E : dest[(x - 1) + (32*(y - 1))];     \
    dest[(x + 2) + (32*(y - 1))] = ( 0x1E > dest[(x + 2) + (32*(y - 1))] ) ? 0x1E : dest[(x + 2) + (32*(y - 1))];     \
    dest[(x + 2) + (32*(y + 2))] = ( 0x1E > dest[(x + 2) + (32*(y + 2))] ) ? 0x1E : dest[(x + 2) + (32*(y + 2))];     \
    dest[(x - 1) + (32*(y + 2))] = ( 0x1E > dest[(x - 1) + (32*(y + 2))] ) ? 0x1E : dest[(x - 1) + (32*(y + 2))];     \
    dest[(x + 0) + (32*(y + 0))] = ( 0x1F > dest[(x + 0) + (32*(y + 0))] ) ? 0x1F : dest[(x + 0) + (32*(y + 0))];     \
    dest[(x + 1) + (32*(y + 0))] = ( 0x1F > dest[(x + 1) + (32*(y + 0))] ) ? 0x1F : dest[(x + 1) + (32*(y + 0))];     \
    dest[(x + 1) + (32*(y + 1))] = ( 0x1F > dest[(x + 1) + (32*(y + 1))] ) ? 0x1F : dest[(x + 1) + (32*(y + 1))];     \
    dest[(x + 0) + (32*(y + 1))] = ( 0x1F > dest[(x + 0) + (32*(y + 1))] ) ? 0x1F : dest[(x + 0) + (32*(y + 1))];     \
    dest[(x - 0) + (32*(y - 1))] = ( 0x1F > dest[(x - 0) + (32*(y - 1))] ) ? 0x1F : dest[(x - 0) + (32*(y - 1))];     \
    dest[(x + 1) + (32*(y - 1))] = ( 0x1F > dest[(x + 1) + (32*(y - 1))] ) ? 0x1F : dest[(x + 1) + (32*(y - 1))];     \
    dest[(x - 1) + (32*(y - 0))] = ( 0x1F > dest[(x - 1) + (32*(y - 0))] ) ? 0x1F : dest[(x - 1) + (32*(y - 0))];     \
    dest[(x - 1) + (32*(y + 1))] = ( 0x1F > dest[(x - 1) + (32*(y + 1))] ) ? 0x1F : dest[(x - 1) + (32*(y + 1))];     \
    dest[(x + 2) + (32*(y + 0))] = ( 0x1F > dest[(x + 2) + (32*(y + 0))] ) ? 0x1F : dest[(x + 2) + (32*(y + 0))];     \
    dest[(x + 2) + (32*(y + 1))] = ( 0x1F > dest[(x + 2) + (32*(y + 1))] ) ? 0x1F : dest[(x + 2) + (32*(y + 1))];     \
    dest[(x + 0) + (32*(y + 2))] = ( 0x1F > dest[(x + 0) + (32*(y + 2))] ) ? 0x1F : dest[(x + 0) + (32*(y + 2))];     \
    dest[(x + 1) + (32*(y + 2))] = ( 0x1F > dest[(x + 1) + (32*(y + 2))] ) ? 0x1F : dest[(x + 1) + (32*(y + 2))];     \
    dest[(x - 0) + (32*(y - 2))] = ( 0x1E > dest[(x - 0) + (32*(y - 2))] ) ? 0x1E : dest[(x - 0) + (32*(y - 2))];     \
    dest[(x - 0) + (32*(y - 3))] = ( 0x1D > dest[(x - 0) + (32*(y - 3))] ) ? 0x1D : dest[(x - 0) + (32*(y - 3))];     \
    dest[(x - 0) + (32*(y - 4))] = ( 0x19 > dest[(x - 0) + (32*(y - 4))] ) ? 0x19 : dest[(x - 0) + (32*(y - 4))];     \
    dest[(x - 0) + (32*(y - 5))] = ( 0x18 > dest[(x - 0) + (32*(y - 5))] ) ? 0x18 : dest[(x - 0) + (32*(y - 5))];     \
    dest[(x + 1) + (32*(y - 2))] = ( 0x1E > dest[(x + 1) + (32*(y - 2))] ) ? 0x1E : dest[(x + 1) + (32*(y - 2))];     \
    dest[(x + 1) + (32*(y - 3))] = ( 0x1D > dest[(x + 1) + (32*(y - 3))] ) ? 0x1D : dest[(x + 1) + (32*(y - 3))];     \
    dest[(x + 1) + (32*(y - 4))] = ( 0x19 > dest[(x + 1) + (32*(y - 4))] ) ? 0x19 : dest[(x + 1) + (32*(y - 4))];     \
    dest[(x + 1) + (32*(y - 5))] = ( 0x18 > dest[(x + 1) + (32*(y - 5))] ) ? 0x18 : dest[(x + 1) + (32*(y - 5))];     \
    dest[(x - 2) + (32*(y + 0))] = ( 0x1E > dest[(x - 2) + (32*(y + 0))] ) ? 0x1E : dest[(x - 2) + (32*(y + 0))];     \
    dest[(x - 3) + (32*(y + 0))] = ( 0x1D > dest[(x - 3) + (32*(y + 0))] ) ? 0x1D : dest[(x - 3) + (32*(y + 0))];     \
    dest[(x - 4) + (32*(y + 0))] = ( 0x19 > dest[(x - 4) + (32*(y + 0))] ) ? 0x19 : dest[(x - 4) + (32*(y + 0))];     \
    dest[(x - 5) + (32*(y + 0))] = ( 0x18 > dest[(x - 5) + (32*(y + 0))] ) ? 0x18 : dest[(x - 5) + (32*(y + 0))];     \
    dest[(x - 2) + (32*(y + 1))] = ( 0x1E > dest[(x - 2) + (32*(y + 1))] ) ? 0x1E : dest[(x - 2) + (32*(y + 1))];     \
    dest[(x - 3) + (32*(y + 1))] = ( 0x1D > dest[(x - 3) + (32*(y + 1))] ) ? 0x1D : dest[(x - 3) + (32*(y + 1))];     \
    dest[(x - 4) + (32*(y + 1))] = ( 0x19 > dest[(x - 4) + (32*(y + 1))] ) ? 0x19 : dest[(x - 4) + (32*(y + 1))];     \
    dest[(x - 5) + (32*(y + 1))] = ( 0x18 > dest[(x - 5) + (32*(y + 1))] ) ? 0x18 : dest[(x - 5) + (32*(y + 1))];     \
    dest[(x + 3) + (32*(y + 1))] = ( 0x1E > dest[(x + 3) + (32*(y + 1))] ) ? 0x1E : dest[(x + 3) + (32*(y + 1))];     \
    dest[(x + 4) + (32*(y + 1))] = ( 0x1D > dest[(x + 4) + (32*(y + 1))] ) ? 0x1D : dest[(x + 4) + (32*(y + 1))];     \
    dest[(x + 5) + (32*(y + 1))] = ( 0x19 > dest[(x + 5) + (32*(y + 1))] ) ? 0x19 : dest[(x + 5) + (32*(y + 1))];     \
    dest[(x + 6) + (32*(y + 1))] = ( 0x18 > dest[(x + 6) + (32*(y + 1))] ) ? 0x18 : dest[(x + 6) + (32*(y + 1))];     \
    dest[(x + 3) + (32*(y + 0))] = ( 0x1E > dest[(x + 3) + (32*(y + 0))] ) ? 0x1E : dest[(x + 3) + (32*(y + 0))];     \
    dest[(x + 4) + (32*(y + 0))] = ( 0x1D > dest[(x + 4) + (32*(y + 0))] ) ? 0x1D : dest[(x + 4) + (32*(y + 0))];     \
    dest[(x + 5) + (32*(y + 0))] = ( 0x19 > dest[(x + 5) + (32*(y + 0))] ) ? 0x19 : dest[(x + 5) + (32*(y + 0))];     \
    dest[(x + 6) + (32*(y + 0))] = ( 0x18 > dest[(x + 6) + (32*(y + 0))] ) ? 0x18 : dest[(x + 6) + (32*(y + 0))];     \
    dest[(x + 1) + (32*(y + 3))] = ( 0x1E > dest[(x + 1) + (32*(y + 3))] ) ? 0x1E : dest[(x + 1) + (32*(y + 3))];     \
    dest[(x + 1) + (32*(y + 4))] = ( 0x1D > dest[(x + 1) + (32*(y + 4))] ) ? 0x1D : dest[(x + 1) + (32*(y + 4))];     \
    dest[(x + 1) + (32*(y + 5))] = ( 0x19 > dest[(x + 1) + (32*(y + 5))] ) ? 0x19 : dest[(x + 1) + (32*(y + 5))];     \
    dest[(x + 1) + (32*(y + 6))] = ( 0x18 > dest[(x + 1) + (32*(y + 6))] ) ? 0x18 : dest[(x + 1) + (32*(y + 6))];     \
    dest[(x + 0) + (32*(y + 3))] = ( 0x1E > dest[(x + 0) + (32*(y + 3))] ) ? 0x1E : dest[(x + 0) + (32*(y + 3))];     \
    dest[(x + 0) + (32*(y + 4))] = ( 0x1D > dest[(x + 0) + (32*(y + 4))] ) ? 0x1D : dest[(x + 0) + (32*(y + 4))];     \
    dest[(x + 0) + (32*(y + 5))] = ( 0x19 > dest[(x + 0) + (32*(y + 5))] ) ? 0x19 : dest[(x + 0) + (32*(y + 5))];     \
    dest[(x + 0) + (32*(y + 6))] = ( 0x18 > dest[(x + 0) + (32*(y + 6))] ) ? 0x18 : dest[(x + 0) + (32*(y + 6))];     \
    dest[(x + 2) + (32*(y - 1))] = ( 0x1E > dest[(x + 2) + (32*(y - 1))] ) ? 0x1E : dest[(x + 2) + (32*(y - 1))];     \
    dest[(x + 2) + (32*(y - 2))] = ( 0x1D > dest[(x + 2) + (32*(y - 2))] ) ? 0x1D : dest[(x + 2) + (32*(y - 2))];     \
    dest[(x + 2) + (32*(y - 3))] = ( 0x1B > dest[(x + 2) + (32*(y - 3))] ) ? 0x1B : dest[(x + 2) + (32*(y - 3))];     \
    dest[(x + 2) + (32*(y - 4))] = ( 0x18 > dest[(x + 2) + (32*(y - 4))] ) ? 0x18 : dest[(x + 2) + (32*(y - 4))];     \
    dest[(x - 1) + (32*(y - 1))] = ( 0x1E > dest[(x - 1) + (32*(y - 1))] ) ? 0x1E : dest[(x - 1) + (32*(y - 1))];     \
    dest[(x - 1) + (32*(y - 2))] = ( 0x1D > dest[(x - 1) + (32*(y - 2))] ) ? 0x1D : dest[(x - 1) + (32*(y - 2))];     \
    dest[(x - 1) + (32*(y - 3))] = ( 0x1B > dest[(x - 1) + (32*(y - 3))] ) ? 0x1B : dest[(x - 1) + (32*(y - 3))];     \
    dest[(x - 1) + (32*(y - 4))] = ( 0x18 > dest[(x - 1) + (32*(y - 4))] ) ? 0x18 : dest[(x - 1) + (32*(y - 4))];     \
    dest[(x - 1) + (32*(y + 2))] = ( 0x1E > dest[(x - 1) + (32*(y + 2))] ) ? 0x1E : dest[(x - 1) + (32*(y + 2))];     \
    dest[(x - 2) + (32*(y + 2))] = ( 0x1D > dest[(x - 2) + (32*(y + 2))] ) ? 0x1D : dest[(x - 2) + (32*(y + 2))];     \
    dest[(x - 3) + (32*(y + 2))] = ( 0x1B > dest[(x - 3) + (32*(y + 2))] ) ? 0x1B : dest[(x - 3) + (32*(y + 2))];     \
    dest[(x - 4) + (32*(y + 2))] = ( 0x18 > dest[(x - 4) + (32*(y + 2))] ) ? 0x18 : dest[(x - 4) + (32*(y + 2))];     \
    dest[(x - 1) + (32*(y - 1))] = ( 0x1E > dest[(x - 1) + (32*(y - 1))] ) ? 0x1E : dest[(x - 1) + (32*(y - 1))];     \
    dest[(x - 2) + (32*(y - 1))] = ( 0x1D > dest[(x - 2) + (32*(y - 1))] ) ? 0x1D : dest[(x - 2) + (32*(y - 1))];     \
    dest[(x - 3) + (32*(y - 1))] = ( 0x1B > dest[(x - 3) + (32*(y - 1))] ) ? 0x1B : dest[(x - 3) + (32*(y - 1))];     \
    dest[(x - 4) + (32*(y - 1))] = ( 0x18 > dest[(x - 4) + (32*(y - 1))] ) ? 0x18 : dest[(x - 4) + (32*(y - 1))];     \
    dest[(x + 2) + (32*(y + 2))] = ( 0x1E > dest[(x + 2) + (32*(y + 2))] ) ? 0x1E : dest[(x + 2) + (32*(y + 2))];     \
    dest[(x + 3) + (32*(y + 2))] = ( 0x1D > dest[(x + 3) + (32*(y + 2))] ) ? 0x1D : dest[(x + 3) + (32*(y + 2))];     \
    dest[(x + 4) + (32*(y + 2))] = ( 0x1B > dest[(x + 4) + (32*(y + 2))] ) ? 0x1B : dest[(x + 4) + (32*(y + 2))];     \
    dest[(x + 5) + (32*(y + 2))] = ( 0x18 > dest[(x + 5) + (32*(y + 2))] ) ? 0x18 : dest[(x + 5) + (32*(y + 2))];     \
    dest[(x + 2) + (32*(y - 1))] = ( 0x1E > dest[(x + 2) + (32*(y - 1))] ) ? 0x1E : dest[(x + 2) + (32*(y - 1))];     \
    dest[(x + 3) + (32*(y - 1))] = ( 0x1D > dest[(x + 3) + (32*(y - 1))] ) ? 0x1D : dest[(x + 3) + (32*(y - 1))];     \
    dest[(x + 4) + (32*(y - 1))] = ( 0x1B > dest[(x + 4) + (32*(y - 1))] ) ? 0x1B : dest[(x + 4) + (32*(y - 1))];     \
    dest[(x + 5) + (32*(y - 1))] = ( 0x18 > dest[(x + 5) + (32*(y - 1))] ) ? 0x18 : dest[(x + 5) + (32*(y - 1))];     \
    dest[(x + 2) + (32*(y + 2))] = ( 0x1E > dest[(x + 2) + (32*(y + 2))] ) ? 0x1E : dest[(x + 2) + (32*(y + 2))];     \
    dest[(x + 2) + (32*(y + 3))] = ( 0x1D > dest[(x + 2) + (32*(y + 3))] ) ? 0x1D : dest[(x + 2) + (32*(y + 3))];     \
    dest[(x + 2) + (32*(y + 4))] = ( 0x1B > dest[(x + 2) + (32*(y + 4))] ) ? 0x1B : dest[(x + 2) + (32*(y + 4))];     \
    dest[(x + 2) + (32*(y + 5))] = ( 0x18 > dest[(x + 2) + (32*(y + 5))] ) ? 0x18 : dest[(x + 2) + (32*(y + 5))];     \
    dest[(x - 1) + (32*(y + 2))] = ( 0x1E > dest[(x - 1) + (32*(y + 2))] ) ? 0x1E : dest[(x - 1) + (32*(y + 2))];     \
    dest[(x - 1) + (32*(y + 3))] = ( 0x1D > dest[(x - 1) + (32*(y + 3))] ) ? 0x1D : dest[(x - 1) + (32*(y + 3))];     \
    dest[(x - 1) + (32*(y + 4))] = ( 0x1B > dest[(x - 1) + (32*(y + 4))] ) ? 0x1B : dest[(x - 1) + (32*(y + 4))];     \
    dest[(x - 1) + (32*(y + 5))] = ( 0x18 > dest[(x - 1) + (32*(y + 5))] ) ? 0x18 : dest[(x - 1) + (32*(y + 5))];     \
    dest[(x - 2) + (32*(y - 2))] = ( 0x1C > dest[(x - 2) + (32*(y - 2))] ) ? 0x1C : dest[(x - 2) + (32*(y - 2))];     \
    dest[(x - 3) + (32*(y - 2))] = ( 0x1A > dest[(x - 3) + (32*(y - 2))] ) ? 0x1A : dest[(x - 3) + (32*(y - 2))];     \
    dest[(x - 2) + (32*(y - 3))] = ( 0x1A > dest[(x - 2) + (32*(y - 3))] ) ? 0x1A : dest[(x - 2) + (32*(y - 3))];     \
    dest[(x - 4) + (32*(y - 2))] = ( 0x18 > dest[(x - 4) + (32*(y - 2))] ) ? 0x18 : dest[(x - 4) + (32*(y - 2))];     \
    dest[(x - 2) + (32*(y - 4))] = ( 0x18 > dest[(x - 2) + (32*(y - 4))] ) ? 0x18 : dest[(x - 2) + (32*(y - 4))];     \
    dest[(x - 3) + (32*(y - 3))] = ( 0x19 > dest[(x - 3) + (32*(y - 3))] ) ? 0x19 : dest[(x - 3) + (32*(y - 3))];     \
    dest[(x - 4) + (32*(y - 3))] = ( 0x18 > dest[(x - 4) + (32*(y - 3))] ) ? 0x18 : dest[(x - 4) + (32*(y - 3))];     \
    dest[(x - 3) + (32*(y - 4))] = ( 0x18 > dest[(x - 3) + (32*(y - 4))] ) ? 0x18 : dest[(x - 3) + (32*(y - 4))];     \
    dest[(x + 3) + (32*(y + 3))] = ( 0x1C > dest[(x + 3) + (32*(y + 3))] ) ? 0x1C : dest[(x + 3) + (32*(y + 3))];     \
    dest[(x + 3) + (32*(y + 4))] = ( 0x1A > dest[(x + 3) + (32*(y + 4))] ) ? 0x1A : dest[(x + 3) + (32*(y + 4))];     \
    dest[(x + 4) + (32*(y + 3))] = ( 0x1A > dest[(x + 4) + (32*(y + 3))] ) ? 0x1A : dest[(x + 4) + (32*(y + 3))];     \
    dest[(x + 3) + (32*(y + 5))] = ( 0x18 > dest[(x + 3) + (32*(y + 5))] ) ? 0x18 : dest[(x + 3) + (32*(y + 5))];     \
    dest[(x + 5) + (32*(y + 3))] = ( 0x18 > dest[(x + 5) + (32*(y + 3))] ) ? 0x18 : dest[(x + 5) + (32*(y + 3))];     \
    dest[(x + 4) + (32*(y + 4))] = ( 0x19 > dest[(x + 4) + (32*(y + 4))] ) ? 0x19 : dest[(x + 4) + (32*(y + 4))];     \
    dest[(x + 4) + (32*(y + 5))] = ( 0x18 > dest[(x + 4) + (32*(y + 5))] ) ? 0x18 : dest[(x + 4) + (32*(y + 5))];     \
    dest[(x + 5) + (32*(y + 4))] = ( 0x18 > dest[(x + 5) + (32*(y + 4))] ) ? 0x18 : dest[(x + 5) + (32*(y + 4))];     \
    dest[(x - 2) + (32*(y + 3))] = ( 0x1C > dest[(x - 2) + (32*(y + 3))] ) ? 0x1C : dest[(x - 2) + (32*(y + 3))];     \
    dest[(x - 3) + (32*(y + 4))] = ( 0x19 > dest[(x - 3) + (32*(y + 4))] ) ? 0x19 : dest[(x - 3) + (32*(y + 4))];     \
    dest[(x - 2) + (32*(y + 4))] = ( 0x1A > dest[(x - 2) + (32*(y + 4))] ) ? 0x1A : dest[(x - 2) + (32*(y + 4))];     \
    dest[(x - 3) + (32*(y + 3))] = ( 0x1A > dest[(x - 3) + (32*(y + 3))] ) ? 0x1A : dest[(x - 3) + (32*(y + 3))];     \
    dest[(x - 4) + (32*(y + 3))] = ( 0x18 > dest[(x - 4) + (32*(y + 3))] ) ? 0x18 : dest[(x - 4) + (32*(y + 3))];     \
    dest[(x - 4) + (32*(y + 4))] = ( 0x18 > dest[(x - 4) + (32*(y + 4))] ) ? 0x18 : dest[(x - 4) + (32*(y + 4))];     \
    dest[(x - 3) + (32*(y + 5))] = ( 0x18 > dest[(x - 3) + (32*(y + 5))] ) ? 0x18 : dest[(x - 3) + (32*(y + 5))];     \
    dest[(x - 2) + (32*(y + 5))] = ( 0x18 > dest[(x - 2) + (32*(y + 5))] ) ? 0x18 : dest[(x - 2) + (32*(y + 5))];     \
    dest[(x + 3) + (32*(y - 2))] = ( 0x1C > dest[(x + 3) + (32*(y - 2))] ) ? 0x1C : dest[(x + 3) + (32*(y - 2))];     \
    dest[(x + 4) + (32*(y - 3))] = ( 0x19 > dest[(x + 4) + (32*(y - 3))] ) ? 0x19 : dest[(x + 4) + (32*(y - 3))];     \
    dest[(x + 4) + (32*(y - 2))] = ( 0x1A > dest[(x + 4) + (32*(y - 2))] ) ? 0x1A : dest[(x + 4) + (32*(y - 2))];     \
    dest[(x + 3) + (32*(y - 3))] = ( 0x1A > dest[(x + 3) + (32*(y - 3))] ) ? 0x1A : dest[(x + 3) + (32*(y - 3))];     \
    dest[(x + 3) + (32*(y - 4))] = ( 0x18 > dest[(x + 3) + (32*(y - 4))] ) ? 0x18 : dest[(x + 3) + (32*(y - 4))];     \
    dest[(x + 4) + (32*(y - 4))] = ( 0x18 > dest[(x + 4) + (32*(y - 4))] ) ? 0x18 : dest[(x + 4) + (32*(y - 4))];     \
    dest[(x + 5) + (32*(y - 3))] = ( 0x18 > dest[(x + 5) + (32*(y - 3))] ) ? 0x18 : dest[(x + 5) + (32*(y - 3))];     \
    dest[(x + 5) + (32*(y - 2))] = ( 0x18 > dest[(x + 5) + (32*(y - 2))] ) ? 0x18 : dest[(x + 5) + (32*(y - 2))];     \

#endif
