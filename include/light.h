#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "utils/types.h"

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

#endif
