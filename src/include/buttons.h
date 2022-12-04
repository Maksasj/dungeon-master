#ifndef _BUTTONS_H_
#define _BUTTONS_H_

#include "types.h"

#define _BUTTONS_ ((vu16*) 0x04000130)

#define _BUTTON_A_      (1 << 0)
#define _BUTTON_B_      (1 << 1)
#define _BUTTON_SELECT_ (1 << 2)
#define _BUTTON_START_  (1 << 3)
#define _BUTTON_RIGHT_  (1 << 4)
#define _BUTTON_LEFT_   (1 << 5)
#define _BUTTON_UP_     (1 << 6)
#define _BUTTON_DOWN_   (1 << 7)
#define _BUTTON_R_      (1 << 8)
#define _BUTTON_L_      (1 << 9)

inline u8 buttonPressed(u16 _button);

#endif
