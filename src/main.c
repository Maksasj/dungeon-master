#define EXTREME_MODE

#include "../include/main.h"

Sprite sprites[_NUM_SPRITES_];
i32 next_sprite_index = 0;
char gameTime[6] = "00:00";

void loadGameSpriteImages() {
    //memcpy16DMA((u16*) _SPRITE_PALETTE_, (u16*) image_palette, _PALETTE_SIZE_);
    memcpy16DMA((u16*) _SPRITE_IMAGE_MEMORY_, (u16*) image_data, (image_width * image_height) / 2);
    
    spriteClear(sprites, &next_sprite_index);
}

void loadMenuSpriteImages() {
    memcpy16DMA((u16*) _SPRITE_PALETTE_, (u16*) menu_image_palette, _PALETTE_SIZE_);
    memcpy16DMA((u16*) _SPRITE_IMAGE_MEMORY_, (u16*) menu_image_data, (menu_image_width * menu_image_height) / 2);
    
    spriteClear(sprites, &next_sprite_index);
}

void mainMenuScene() {
    loadMenuSpriteImages();
    
    setLightLayer(0x0);

    u32 _seed = 0;
    u16 MAP[1024];
    
    i8 down_pressed = 0;
    i8 up_pressed = 0;
    i32 selection = 0;

    _INIT_MAIN_MENU_SPRITES_

    int i;
    int j;

    for(i = 0; i < 15; ++i) { 
        for(j = 0; j < 10; ++j) {
            MAP[i*2 + j*2 * 32] = 0x0015;
            MAP[i*2 + j*2 * 32 + 1] = 0x0016;
            MAP[i*2 + j*2 * 32 + 32] = 0x0035;
            MAP[i*2 + j*2 * 32 + 33] = 0x0036;
        }
    }

    memcpy16DMA((u16*) screenBlock(1), (u16*) MAP, 32 * 32);

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

        waitVBlank();
    }

    {
        int k;
        int o;
        for(k = 0; k < 32; ++k) {
            for(o = 0; o < 256; ++o) {
                _SMOOTH_PALETT_TRANSITION_(_SPRITE_PALETTE_, 0, o);
                _SMOOTH_PALETT_TRANSITION_(_BG_PALETTE_, 0, o);
            }

            waitVBlank();
            delay(TRANSITION_SPEED);
        }
    }   

    setSeed(_seed);

    spriteClear(sprites, &next_sprite_index);
    spriteUpdateAll(sprites);
}

void classChooseScene(Class *class) {
    spriteClear(sprites, &next_sprite_index);
    loadGameSpriteImages();

    int i;
    int j;

    setLightLayer(0x0);

    u16 MAP[1024];
    for(i = 0; i < 15; ++i) { 
        for(j = 0; j < 10; ++j) {
            MAP[i*2 + j*2 * 32] = 0x0015;
            MAP[i*2 + j*2 * 32 + 1] = 0x0016;
            MAP[i*2 + j*2 * 32 + 32] = 0x0035;
            MAP[i*2 + j*2 * 32 + 33] = 0x0036;
        }
    }

    vu16* lightLayer = screenBlock(2);

    _RENDER_CHOOSE_SCREEN_;
    
    vu16* baseLayer = screenBlock(1);
    memcpy16DMA((u16*) baseLayer, (u16*) MAP, 32 * 32);

    i8 down_pressed = 0;
    i8 up_pressed = 0;
    i32 selection = 0;

    i32 prev_selection = -1;

    Sprite* warriorIcon = spriteInit(sprites, &next_sprite_index, 48, 80, SIZE_16_16, 0, 0, 0 + 8, 0);
    Sprite* wizzardIcon = spriteInit(sprites, &next_sprite_index, 112, 80, SIZE_16_16, 0, 0, 744 + 8, 0);
    Sprite* archerIcon = spriteInit(sprites, &next_sprite_index, 176, 80, SIZE_16_16, 0, 0, 768 + 8, 0);

    //Text classNameText; 
    //loadTextGlyphs(sprites, &next_sprite_index, &classNameText, "Warrior", (ivec2){.x = 96, .y = 144});
    
    _RENDER_ARROW_UP_(lightLayer, 5, 14);
    _RENDER_ARROW_DOWN_(lightLayer, 5,  6);
    
    spriteUpdateAll(sprites);
    {
        int k;
        int o;
        for(k = 0; k < 32; ++k) {
            for(o = 0; o < 256; ++o) {
                _SMOOTH_PALETT_TRANSITION_(_SPRITE_PALETTE_, image_palette[o], o);
                _SMOOTH_PALETT_TRANSITION_(_BG_PALETTE_, BACKGROUND_PALETTE[o], o);
            }

            waitVBlank();
            delay(TRANSITION_SPEED);
        } 
    }

    i8 flag = 1;
    while(flag) { 
        if(buttonPressed(_BUTTON_RIGHT_) && down_pressed == 0) {
            if(selection == 2)
                selection = 0;
            else
                ++selection;


            down_pressed = 1;
            notePlay(NOTE_B, 0);
        }

        if(buttonPressed(_BUTTON_LEFT_) && up_pressed == 0) {
            if(selection == 0)
                selection = 2;
            else
                --selection;

            up_pressed = 1;
            notePlay(NOTE_B, 0);
        }

        if(selection != prev_selection) {
            switch (selection) {
            case 0:
                _CLEAR_TILE_(lightLayer, 13, 14);
                _CLEAR_TILE_(lightLayer, 13, 6);
                _CLEAR_TILE_(lightLayer, 21, 14);
                _CLEAR_TILE_(lightLayer, 21, 6);

                _RENDER_ARROW_UP_(lightLayer, 5, 14);
                _RENDER_ARROW_DOWN_(lightLayer, 5,  6);
                //updateTextGlyphs(&classNameText, "Warrior", (ivec2){.x = 96, .y = 144});
                break;
            case 1:
                _CLEAR_TILE_(lightLayer, 5, 14);
                _CLEAR_TILE_(lightLayer, 5, 6);
                _CLEAR_TILE_(lightLayer, 21, 14);
                _CLEAR_TILE_(lightLayer, 21, 6);

                _RENDER_ARROW_UP_(lightLayer, 13, 14);
                _RENDER_ARROW_DOWN_(lightLayer, 13, 6);
                //updateTextGlyphs(&classNameText, "Wizard ", (ivec2){.x = 96, .y = 144});
                break;
            case 2:
                _CLEAR_TILE_(lightLayer, 5, 14);
                _CLEAR_TILE_(lightLayer, 5, 6);
                _CLEAR_TILE_(lightLayer, 13, 14);
                _CLEAR_TILE_(lightLayer, 13, 6);

                _RENDER_ARROW_UP_(lightLayer, 21, 14);
                _RENDER_ARROW_DOWN_(lightLayer, 21, 6);
                //updateTextGlyphs(&classNameText, "Archer ", (ivec2){.x = 96, .y = 144});
                break;
            default:
                break;
            }

            prev_selection = selection;
        }

        if(!buttonPressed(_BUTTON_RIGHT_))
            down_pressed = 0;

        if(!buttonPressed(_BUTTON_LEFT_))
            up_pressed = 0;

        if(buttonPressed(_BUTTON_START_)) {
            setLightLayer(0x0);
            switch (selection) {
            case 0:
                (*class) = WARRIOR;
                flag = 0;
                break;
            case 1:
                (*class) = WIZARD;
                flag = 0;
                break;
            case 2:
                (*class) = ARCHER;
                flag = 0;
                break;
            default:
                break;
            }
        }
            
        waitVBlank();
        spriteUpdateAll(sprites);
    }

    {
        int k;
        int o;
        for(k = 0; k < 32; ++k) {
            for(o = 0; o < 256; ++o) {
                _SMOOTH_PALETT_TRANSITION_(_SPRITE_PALETTE_, 0, o);
                _SMOOTH_PALETT_TRANSITION_(_BG_PALETTE_, 0, o);
            }

            waitVBlank();
            delay(TRANSITION_SPEED);
        }
    }
}

void gameCompleteScene() {
    vu16* lightLayer = screenBlock(2);
    setLightLayer(0x1E);
    _RENDER_SIDE_SHADOW_(lightLayer);

    spriteUpdateAll(sprites);
    int k;
    int o;
    for(k = 0; k < 32; ++k) {
        for(o = 0; o < 256; ++o) {
            _SMOOTH_PALETT_TRANSITION_(_SPRITE_PALETTE_, image_palette[o], o);
            _SMOOTH_PALETT_TRANSITION_(_BG_PALETTE_, BACKGROUND_PALETTE[o], o);
        }

        waitVBlank();
        delay(TRANSITION_SPEED);
    }
    //Text gameCompletedText; 
    //Text timeText; 
    //Text anothertimeText; 
    //Text pressStartText;
    //loadTextGlyphs(sprites, &next_sprite_index, &gameCompletedText, "GAME COMPLETED", (ivec2){.x = 72, .y = 32});
    //loadTextGlyphs(sprites, &next_sprite_index, &timeText, "Time:", (ivec2){.x = 80, .y = 52});
    //loadTextGlyphs(sprites, &next_sprite_index, &anothertimeText, gameTime, (ivec2){.x = 128, .y = 52});
//
    //loadTextGlyphs(sprites, &next_sprite_index, &anothertimeText, "press start to play", (ivec2){.x = 52, .y = 132});

    while (1) {
        waitVBlank();
        spriteUpdateAll(sprites);

        if(buttonPressed(_BUTTON_START_)) {
            game_completed = 0;
            return;
        }
    }
}

void gameFailedScene() {
    vu16* lightLayer = screenBlock(2);
    setLightLayer(0x1E);
    _RENDER_SIDE_SHADOW_(lightLayer);

    //Text gameCompletedText; 
    //Text timeText; 
    //Text anothertimeText; 
    //Text pressStartText;
    //loadTextGlyphs(sprites, &next_sprite_index, &gameCompletedText, "YOU DIED", (ivec2){.x = 72, .y = 32});
    //loadTextGlyphs(sprites, &next_sprite_index, &timeText, "Time:", (ivec2){.x = 80, .y = 52});
    //loadTextGlyphs(sprites, &next_sprite_index, &anothertimeText, gameTime, (ivec2){.x = 128, .y = 52});
//
    //loadTextGlyphs(sprites, &next_sprite_index, &anothertimeText, "press start to play", (ivec2){.x = 52, .y = 132});

    while (1) {
        waitVBlank();
        spriteUpdateAll(sprites);

        if(buttonPressed(_BUTTON_START_)) {
            game_completed = 0;
            return;
        }
    }
}

int gameScene(Class *chosenClass) {
    World world = {.floorCount = 1};
    
    loadGameSpriteImages();
    #ifdef _LIGHT_ON_
        setLightLayer(0x17);
    #endif

    Entity player;

    switch (*chosenClass) {
        case WARRIOR: {
            player = entityInit(newIVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8), stats(5, 1, 0, 1, 0), PLAYER, 0);
            player.attack_callback = &warriorAttack;
            player.calculate_damage_callback = &warriorCalculateDamage;
            player.sprite_offset = 0;
            break;
        }
        case WIZARD: {
            player = entityInit(newIVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8), stats(5, 1, 1, 0, 0), PLAYER, 0);
            player.attack_callback = &wizardAttack;
            player.calculate_damage_callback = &wizardCalculateDamage;
            player.sprite_offset = 744;
            break;
        }
        case ARCHER: {
            player = entityInit(newIVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8), stats(5, 2, 0, 0, 0), PLAYER, 0);
            player.attack_callback = &archerAttack;
            player.calculate_damage_callback = &archerCalculateDamage;
            player.sprite_offset = 768;
            break;
        }
        default:
            break;
    }

    entityInitSprite(&player, sprites, &next_sprite_index);
    spriteSetOffset(player.sprite, player.sprite_offset);

    /* For now we will manually update player */
    // player.update_callback = &player_update;
    player.die_callback = &killPlayer;
    player.dodge_callback = &playerTryDodge;

    player.spec = malloc(sizeof(PlayerSpecData));
    initPlayerSpec(sprites, &next_sprite_index, &player, player.spec, *chosenClass);
    
    generateFloor(&world, *chosenClass);
    gotoRoom(&world, 0, sprites, &next_sprite_index);

    #ifdef _LIGHT_ON_
        vu16* lightLayer = screenBlock(2);

        int prevTileX = ((int) player.position.x) >> POSITION_FIXED_SCALAR;
        int prevTileY = ((int) player.position.y) >> POSITION_FIXED_SCALAR;

        prevTileX /= 8;
        prevTileY /= 8;

        RENDER_LIGHT_BULB(screenBlock(2), prevTileX, prevTileY);
    #endif

    renderText((u16*) screenBlock(0), gameTime, (ivec2){.x = 25, .y = 18});
    
    Timer timer;
    initTimer(&timer);
    startTimer(&timer);

    i32 prevSecond = GET_GLOBAL_TIME;
    i32 activeRoom = world.activeRoom;
    
    updatePlayerSpec(player.spec, &player);
    spriteUpdateAll(sprites);
    {
        int k;
        int o;
        for(k = 0; k < 32; ++k) {
            for(o = 0; o < 256; ++o) {
                _SMOOTH_PALETT_TRANSITION_(_SPRITE_PALETTE_, image_palette[o], o);
                _SMOOTH_PALETT_TRANSITION_(_BG_PALETTE_, BACKGROUND_PALETTE[o], o);
            }

            waitVBlank();
            delay(TRANSITION_SPEED);
        } 
    }
        
    u16* palettes[] = {
        RED_PINK_WALLS_GREEN_DOORS,
        BLUE_WALLS_YELLOW_DOORS,
        NEON_1,
        NEON_2,
        BLACK_AND_WHITE,
        GREY,
        GREEN_PINK_DOORS,
        PINK_BLUE_DOORS,
        DEFAULT_PALETTE
    };

    setPalette(BACKGROUND_PALETTE, getRandomPalette(palettes));

    while (1) {
        updateWorld(&world, &player);
        entityUpdate(&player);

        if(room_switch || floor_switch) {
            setPalette(BACKGROUND_PALETTE, getRandomPalette(palettes));
            spriteUpdateAll(sprites);
            int k;
            int o;
            for(k = 0; k < 32; ++k) {
                for(o = 0; o < 256; ++o) {
                    _SMOOTH_PALETT_TRANSITION_(_SPRITE_PALETTE_, image_palette[o], o);
                    _SMOOTH_PALETT_TRANSITION_(_BG_PALETTE_, BACKGROUND_PALETTE[o], o);
                }

                waitVBlank();
                delay(TRANSITION_SPEED);
            }

            room_switch = 0;
            floor_switch = 0;
        }

        if(prevSecond != GET_GLOBAL_TIME || activeRoom != world.activeRoom) {
            ivec3 time = formatTime(&timer);

            gameTime[0] = 48 + time.y / 10;
            gameTime[1] = 48 + time.y % 10;
            gameTime[3] = 48 + time.z / 10;
            gameTime[4] = 48 + time.z % 10;
            renderText((u16*) screenBlock(0), gameTime, (ivec2){.x = 25, .y = 18});

            prevSecond = GET_GLOBAL_TIME;
        }

        #ifdef _LIGHT_ON_
            int playerX = ((int) player.position.x) >> POSITION_FIXED_SCALAR;
            int playerY = ((int) player.position.y) >> POSITION_FIXED_SCALAR;

            playerX /= 8;
            playerY /= 8;

            if((prevTileX != playerX) || (prevTileY != playerY)) {
                SHADOW_BULB(screenBlock(2), prevTileX, prevTileY);
                prevTileX = playerX;
                prevTileY = playerY;
                RENDER_DYNAMIC_LIGHT_BULB(screenBlock(2), playerX, playerY);
            }
        #endif

        updatePlayerSpec(player.spec, &player);
        //(player.update_callback)(&player, &world, &world.rooms[world.activeRoom]);        
        player_update(&player, &world, &world.rooms[world.activeRoom]);

        if(player.health <= 0 || game_completed == 1) {
            setScreenBlock(screenBlock(0), 0);

            ivec3 time = formatTime(&timer);

            gameTime[0] = 48 + time.y / 10;
            gameTime[1] = 48 + time.y % 10;
            gameTime[3] = 48 + time.z / 10;
            gameTime[4] = 48 + time.z % 10;
            spriteUpdateAll(sprites);

            free(player.spec);

            setPalette(BACKGROUND_PALETTE, DEFAULT_PALETTE);

            if(game_completed == 1)
                return 1;
            
            return 0;
        }

        spriteUpdateAll(sprites);

        #ifndef EXTREME_MODE
            waitVBlank();
        #else
            delay(30);
        #endif
    }
}

int main() {
    *_DISPLAY_CONTROL_ = 
        _DISPLAY_CONTROL_MODE_0_ | 
        _DISPLAY_CONTROL_BG_0_ | 
        _DISPLAY_CONTROL_BG_1_ | 
        _DISPLAY_CONTROL_BG_2_ | 
        _SPRITE_ENABLE_ | 
        _SPRITE_MAP_1D_;

    counterInit();
    counterStart();

    interruptionInit(onVBlank);
    soundInit(5, 3, 0, 3);
    playSound(GAME_SOUNDTRACK, _GAME_SOUNDTRACK_BYTES_, 8000, 'A');

    initBackground(BACKGROUND_PALETTE, BACKGROUND_DATA, _BACKGROUND_WIDTH_, _BACKGROUND_HEIGHT_);
    
    setLightLayer(0x0);

    Class chosen_class;
    ActiveScene active_scene = MAIN_MENU_SCENE;

    while (1) {
        if(active_scene == MAIN_MENU_SCENE) {
            mainMenuScene();
            active_scene = CHOOSE_SCENE;
        } else if(active_scene == CHOOSE_SCENE) {
            classChooseScene(&chosen_class);
            active_scene = GAME_SCENE;
        } else if(active_scene == GAME_SCENE) {
            int rez = gameScene(&chosen_class);

            if(rez == 1)
                active_scene = GAME_COMPLETE;
            else
                active_scene = GAME_FAILED;
        } else if(active_scene == GAME_COMPLETE) {
            gameCompleteScene();
            active_scene = MAIN_MENU_SCENE;
        } else if(active_scene == GAME_FAILED) {
            gameFailedScene();
            active_scene = MAIN_MENU_SCENE;
        }
    }
    
    return 0;
}
