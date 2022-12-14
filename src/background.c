#include "../include/background.h"

#include "../assets/generated/tile-map.h"

vu16* charBlock(u32 _block) {
    return (vu16*) (_TILEMAP_ + (_block * _CHAR_BLOCK_SIZE_));
}

vu16* screenBlock(u32 _block) {
    return (vu16*) (_TILEMAP_ + (_block * _SCREEN_BLOCK_SIZE_));
}

void initBackground() {
    memcpy16DMA((u16*) _BG_PALETTE_, (u16*) BACKGROUND_PALETTE, _PALETTE_SIZE_);
    
    memcpy16DMA((u16*) charBlock(0), (u16*) BACKGROUND_DATA, (_BACKGROUND_WIDTH_ * _BACKGROUND_HEIGHT_) / 2);
    *_BG0_CONTROL_ = 3 |            // priority, 0 is highest, 3 is lowest
        (0 << 2)  |                 // the char block the image data is stored in
        (0 << 6)  |                 // the mosaic flag
        (1 << 7)  |                 // color mode, 0 is 16 colors, 1 is 256 colors
        (31 << 8) |                  // the screen block the tile data is stored in
        (1 << 13) |                 // wrapping flag
        (0 << 14);                  // bg size, 0 is 256x256

    memcpy16DMA((u16*) charBlock(1), (u16*) BACKGROUND_DATA, (_BACKGROUND_WIDTH_ * _BACKGROUND_HEIGHT_) / 2);
    *_BG1_CONTROL_ = 2 |            // priority, 0 is highest, 3 is lowest
        (1 << 2)  |                 // the char block the image data is stored in
        (0 << 6)  |                 // the mosaic flag
        (1 << 7)  |                 // color mode, 0 is 16 colors, 1 is 256 colors
        (13 << 8) |                 // the screen block the tile data is stored in
        (1 << 13) |                 // wrapping flag
        (0 << 14);                  // bg size, 0 is 256x256
}
 