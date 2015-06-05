//
//  GameManager.h
//  Space Invaders
//
//  Created by Ramy Fawaz on 6/2/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#include "PlayerShip.h"
#include "BasicEnemy.h"
#include "Block.h"

#ifndef Space_Invaders_GameManager_h
#define Space_Invaders_GameManager_h

class GameManager
{
public:
    GameManager();
    
    bool init();
    bool loadMedia();
    
    void loadLevelOne();
    void handleEvent(SDL_Event e);
    void updatePosition();
    void renderObjects();
    void clearScreen();
    void updateScreen();
    void close();
    
private:
    SDL_Window* gWindow = NULL;         //Main Window
    SDL_Renderer* gRenderer = NULL;     //Window Renderer
    LTexture shipTexture;  //Scene texture
    LTexture enemyTexture;
    LTexture blockTexture;
    PlayerShip mainShip;
    Block blocks[4];
    BasicEnemy bEnemy[22];
};
#endif
