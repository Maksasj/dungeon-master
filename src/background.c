#include "include/background.h"

#include "assets/background.h"

/* return a pointer to one of the 4 character blocks (0-3) */
vu16* charBlock(u32 _block) {
    /* they are each 16K big */
    return (vu16*) (_TILEMAP_ + (_block * _CHAR_BLOCK_SIZE_));
}

/* return a pointer to one of the 32 screen blocks (0-31) */
vu16* screenBlock(u32 _block) {
    /* they are each 2K big */
    return (vu16*) (_TILEMAP_ + (_block * _SCREEN_BLOCK_SIZE_));
}

void initBackground() {
    memcpy16DMA((u16*) _BG_PALETTE_, (u16*) BACKGROUND_PALETTE, _PALETTE_SIZE_);
    memcpy16DMA((u16*) charBlock(0), (u16*) BACKGROUND_DATA,
            (_BACKGROUND_WIDTH_ * _BACKGROUND_HEIGHT_) / 2);

    *_BG0_CONTROL_ = 0 |    /* priority, 0 is highest, 3 is lowest */
        (0 << 2)  |       /* the char block the image data is stored in */
        (0 << 6)  |       /* the mosaic flag */
        (1 << 7)  |       /* color mode, 0 is 16 colors, 1 is 256 colors */
        (13 << 8) |       /* the screen block the tile data is stored in */
        (1 << 13) |       /* wrapping flag */
        (3 << 14);        /* bg size, 0 is 256x256 */
}
