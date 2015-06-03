//
//  PlayerShip.h
//  Space Invaders
//
//  Created by Ramy Fawaz on 5/17/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//


#include "LTexture.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

#ifndef Space_Invaders_PlayerShip_h
#define Space_Invaders_PlayerShip_h

class PlayerShip
{
public:
    PlayerShip();
    PlayerShip(LTexture* shipTexture);
    ~PlayerShip();
    
    void setTexture (LTexture* shipTexture);
    void handleEvent( SDL_Event& e );
    void move();
    void render();
private:
    int lives = 3;
    int mPosX, mPosY;
    int mVelX;
    const int velocity = 10;
    LTexture* texture;
};

#endif
