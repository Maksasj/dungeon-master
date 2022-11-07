#ifndef DEFINES_H
#define DEFINES_H

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160

/* the tile mode flags needed for display control register */
#define MODE0 0x00
#define BG0_ENABLE 0x100

/* flags to set sprite handling in display control register */
#define SPRITE_MAP_2D 0x0
#define SPRITE_MAP_1D 0x40
#define SPRITE_ENABLE 0x1000

/* flag for turning on DMA */
#define DMA_ENABLE 0x80000000

/* flags for the sizes to transfer, 16 or 32 bits */
#define DMA_16 0x00000000
#define DMA_32 0x04000000

/* the control registers for the four tile layers */
#define bg0_control ((volatile unsigned short*) 0x4000008)

/* the display control pointer points to the gba graphics register */
#define display_control ((volatile unsigned long*) 0x4000000)

/* the memory location which controls sprite attributes */
#define sprite_attribute_memory ((volatile unsigned short*) 0x7000000)

/* the memory location which stores sprite image data */
#define sprite_image_memory ((volatile unsigned short*) 0x6010000)

/* the address of the color palettes used for backgrounds and sprites */
#define bg_palette ((volatile unsigned short*) 0x5000000)
#define sprite_palette ((volatile unsigned short*) 0x5000200)

/* the button register holds the bits which indicate whether each button has
 * been pressed - this has got to be volatile as well
 */
#define buttons ((volatile unsigned short*) 0x04000130)

/* scrolling registers for backgrounds */
#define bg0_x_scroll ((unsigned short*) 0x4000010)
#define bg0_y_scroll ((unsigned short*) 0x4000012)

#define scanline_counter ((volatile unsigned short*) 0x4000006)

/* the tile mode flags needed for display control register */
#define MODE0 0x00
#define BG0_ENABLE 0x100

/* flags to set sprite handling in display control register */
#define SPRITE_MAP_2D 0x0
#define SPRITE_MAP_1D 0x40
#define SPRITE_ENABLE 0x1000

/* the bit positions indicate each button - the first bit is for A, second for
 * B, and so on, each constant below can be ANDED into the register to get the
 * status of any one button */
#define BUTTON_A (1 << 0)
#define BUTTON_B (1 << 1)
#define BUTTON_SELECT (1 << 2)
#define BUTTON_START (1 << 3)
#define BUTTON_RIGHT (1 << 4)
#define BUTTON_LEFT (1 << 5)
#define BUTTON_UP (1 << 6)
#define BUTTON_DOWN (1 << 7)
#define BUTTON_R (1 << 8)
#define BUTTON_L (1 << 9)

/* flag for turning on DMA */
#define DMA_ENABLE 0x80000000

/* flags for the sizes to transfer, 16 or 32 bits */
#define DMA_16 0x00000000
#define DMA_32 0x04000000

#define dma_source ((volatile unsigned int*) 0x40000D4)

/* pointer to the DMA destination location */
#define dma_destination ((volatile unsigned int*) 0x40000D8)

/* pointer to the DMA count/control */
#define dma_count ((volatile unsigned int*) 0x40000DC)

#endif