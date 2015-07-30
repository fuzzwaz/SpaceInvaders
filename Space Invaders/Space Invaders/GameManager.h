//
//  GameManager.h
//  Space Invaders
//
//  Created by Ramy Fawaz on 6/2/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#ifndef Space_Invaders_GameManager_h
#define Space_Invaders_GameManager_h

#include "PlayerShip.h"
#include "BasicEnemy.h"
#include "Block.h"
#include "CEvent.h"
#include "vector"

class GameManager
{
public:
    
    bool init();
    bool loadMedia();
    
    void loadLevelOne();
    void handleEvent(SDL_Event e);
    void handleCEvent(CEvent e, int = -1);
    void updatePosition();
    void renderObjects();
    void clearScreen();
    void updateScreen();
    void close();
    void checkCollisions();
    
    LTexture* getShotTexture();
    SDL_Renderer* getRenderer();
    static GameManager* getGameManager();
    
private:
    
    GameManager();
    
    SDL_Window* gWindow = NULL;         //Main Window
    SDL_Renderer* gRenderer = NULL;     //Window Renderer
    LTexture shipTexture;               //Scene texture
    LTexture enemyTexture;
    LTexture blockTexture;
    LTexture* shotTexture;
    PlayerShip* mainShip;
    Block blocks[4];
    BasicEnemy bEnemy[22];
    std::vector<PlayerShot*> shots;
    
    int blockRange[2];
    int row1Range[2];
    int row2Range[2];
    
    static GameManager* gameManager;

};
#endif
