//
//  PlayerShip.h
//  Space Invaders
//
//  Created by Ramy Fawaz on 5/17/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#ifndef Space_Invaders_PlayerShip_h
#define Space_Invaders_PlayerShip_h

#include "LTexture.h"
#include "CEvent.h"

class GameManager;
class PlayerShot;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 750;

class PlayerShip
{
public:
    PlayerShip();
    PlayerShip(LTexture* shipTexture);
    ~PlayerShip();
    
    void setTexture (LTexture* shipTexture);
    void handleEvent( SDL_Event& e );
    void setPos(int xPos, int yPos);
    void move();
    void render();
    
    void setGameManager(GameManager*);
    GameManager* getGameManager();
    
    int getWidth();
    int getHeight();
    int getXPos();
    int getYPos();
private:
    int lives = 3;
    int shipWidth = 80;
    int shipHeight = 40;
    int mPosX, mPosY;
    int mVelX;
    const int velocity = 10;
    LTexture* texture;
    
    GameManager* gameManager;
    
};

#endif
