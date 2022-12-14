/**
 * interruption
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Allows to manipulate with GBA interruptions
*/

#ifndef _INTERRUPTION_H_
#define _INTERRUPTION_H_

#include "../utils/types.h"

// Interrupt Master Enable Register
#define _INTERRUPT_ENABLE_ ((u16*) 0x4000208)

// Interrupt Enable Register
#define _INTERRUPT_SELECTION_ ((u16*) 0x4000200)

// Interrupt Request Flags / IRQ Acknowledge
#define _INTERRUPT_STATE_ ((u16*) 0x4000202)

// Pointer to user IRQ handler (32bit ARM code)
#define _INTERRUPT_CALLBACK_ ((u32*) 0x3007FFC)

// This register controls the LCD interrupts.
#define _DISPLAY_INTERRUPTS_ ((u16*) 0x4000004)

// Interruption bites
#define _INT_VBLANK_    0x0001
#define _INT_HBLANK_    0x0002
#define _INT_VCOUNT_    0x0004
#define _INT_TIMER_0_   0x0008
#define _INT_TIMER_1_   0x0010
#define _INT_TIMER_2_   0x0020
#define _INT_TIMER_3_   0x0040
#define _INT_COM_       0x0080
#define _INT_DMA_0_     0x0100
#define _INT_DMA_1_     0x0200
#define _INT_DMA_2_     0x0400
#define _INT_DMA_3_     0x0800
#define _INT_BUTTON_    0x1000
#define _INT_CART_      0x2000

/**
 * Initialize interruption
 * 
 * @param   _ptr   interruption
*/
void interruptionInit(void (*_ptr)());

#endif
