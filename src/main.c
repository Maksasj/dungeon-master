#define EXTREME_MODE

#include "../include/main.h"

int main() {
    *_DISPLAY_CONTROL_ = 
        _DISPLAY_CONTROL_MODE_0_ | 
        _DISPLAY_CONTROL_BG_0_ | 
        _DISPLAY_CONTROL_BG_1_ | 
        _SPRITE_ENABLE_ | 
        _SPRITE_MAP_1D_;

    counterInit();
    counterStart();

    Sprite sprites[_NUM_SPRITES_];
    i32 next_sprite_index = 0;

    initBackground();
    
    memcpy16DMA((u16*) _SPRITE_PALETTE_, (u16*) menu_image_palette, _PALETTE_SIZE_);
    memcpy16DMA((u16*) _SPRITE_IMAGE_MEMORY_, (u16*) menu_image_data, (menu_image_width * menu_image_height) / 2);
    spriteClear(sprites, &next_sprite_index);

    u16 MAP[1024];
    
    i8 down_pressed = 0;
    i8 up_pressed = 0;
    i32 selection = 0;

    interruptionInit(onVBlank);
    soundInit(5, 3, 0, 3);

    i32 i; i32 j;

    _INIT_MAIN_MENU_SPRITES_
    _INIT_MAIN_MENU_BACKGROUND_
    
    memcpy16DMA((u16*) screenBlock(31), (u16*) MAP, 32 * 32);
    
    vu16* pointer = screenBlock(13);

    int x;
    int y;
    for(x = 0; x < 30; ++x) {
        for(y = 0; y < 20; ++y) {
            pointer[x + 32*y] = 0x0;
        }
    }
    
    u32 _seed = 0;
    while(1) {
        ++_seed;

        if(buttonPressed(_BUTTON_DOWN_) && down_pressed == 0) {
            selection = selection == 0 ? MAIN_MENU_OPTION_COUNT - 1 : selection - 1;
            down_pressed = 1;
            notePlay(NOTE_B, 0);
        }

        if(buttonPressed(_BUTTON_UP_) && up_pressed == 0) {
            selection = selection == MAIN_MENU_OPTION_COUNT - 1 ? 0 : selection + 1;
            up_pressed = 1;
            notePlay(NOTE_B, 0);
        }

        if(!buttonPressed(_BUTTON_DOWN_))
            down_pressed = 0;

        if(!buttonPressed(_BUTTON_UP_))
            up_pressed = 0;

        switch (selection) {
            case 0: {
                spritePosition(selectionArrow, 130, 59);
                spriteSetOffset(buttonPlay, 0); 
                spriteSetOffset(buttonAbout, 960); 
                break;
            }
            case 1: {
                spritePosition(selectionArrow, 130, 100);
                spriteSetOffset(buttonPlay, 896);
                spriteSetOffset(buttonAbout, 64);
                break;
            }
        }

        if(buttonPressed(_BUTTON_SELECT_)) {
            if(selection == 0) {
                break;
            } else if(selection == 1) {
                notePlay(NOTE_GIS, 0);
            }
        }

        spriteUpdateAll(sprites);
    }
    
    setSeed(_seed);

    World world;
    world.floorCount = 3;
    generateFloor(&world);
    
    memcpy16DMA((u16*) _SPRITE_PALETTE_, (u16*) image_palette, _PALETTE_SIZE_);
    memcpy16DMA((u16*) _SPRITE_IMAGE_MEMORY_, (u16*) image_data, (image_width * image_height) / 2);
    spriteClear(sprites, &next_sprite_index);

    playSound(GAME_SOUNDTRACK, _GAME_SOUNDTRACK_BYTES_, 8000, 'A');

    gotoRoom(&world, 0, sprites, &next_sprite_index);

    Entity player;
    Class chosen_class = WIZARD;

    switch (chosen_class) {
        case WARRIOR: {
            player = entityInit(newFVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8), stats(3, 1, 0, 1, 0), PLAYER, 0);
            player.attack_callback = &warriorAttack;
            player.calculate_damage_callback = &warriorCalculateDamage;
            break;
        }
        case WIZARD: {
            player = entityInit(newFVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8), stats(3, 1, 1, 0, 0), PLAYER, 0);
            player.attack_callback = &wizardAttack;
            break;
        }
        case ARCHER: {
            player = entityInit(newFVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8), stats(3, 2, 0, 0, 0), PLAYER, 0);
            player.attack_callback = &archerAttack;
            break;
        }
        default:
            break;
    }

    entityInitSprite(&player, sprites, &next_sprite_index);
    player.update_callback = &playerUpdate;
    player.die_callback = &killPlayer;
    player.dodge_callback = &playerTryDodge;

    PlayerUI playerUI;
    initPlayerUI(&playerUI, sprites, &next_sprite_index);

    player.spec = malloc(sizeof(PlayerSpecData));
    initPlayerSpec(sprites, &next_sprite_index, &player, player.spec, &playerUI, chosen_class);

    //Text text;
    //loadTextGlyphs(sprites, &next_sprite_index, &text, "Privet soskar !");
    
    Timer timer;
    initTimer(&timer);
    startTimer(&timer);

    for(x = 0; x < 30; ++x)
        for(y = 0; y < 20; ++y)
            pointer[x + 32*y] = 0x17;
    
    int prevTileX = ((int) player.position.x) >> POSITION_FIXED_SCALAR;
    int prevTileY = ((int) player.position.y) >> POSITION_FIXED_SCALAR;
    
    /*
    ivec3 time = formatTime(&timer);
    log(LOG_INFO, "%d:%d:%d", time.x, time.y, time.z);
    */

    prevTileX /= 8;
    prevTileY /= 8;

    RENDER_LIGHT_BULB(pointer, prevTileX, prevTileY);

    while (1) {
        updateWorld(&world, &player);
        entityUpdate(&player);

        int playerX = ((int) player.position.x) >> POSITION_FIXED_SCALAR;
        int playerY = ((int) player.position.y) >> POSITION_FIXED_SCALAR;

        playerX /= 8;
        playerY /= 8;

        if((prevTileX != playerX) || (prevTileY != playerY)) {
            SHADOW_BULB(pointer, prevTileX, prevTileY);
            prevTileX = playerX;
            prevTileY = playerY;
            RENDER_DYNAMIC_LIGHT_BULB(pointer, playerX, playerY);
        }

        updatePlayerSpec(player.spec, &player);
        (player.update_callback)(&player, &world, &world.rooms[world.activeRoom]);

        spriteUpdateAll(sprites);

        #ifndef EXTREME_MODE
            waitVBlank();
        #else
            delay(50);
        #endif
    }
}
