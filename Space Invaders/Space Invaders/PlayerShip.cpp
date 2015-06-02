//
//  PlayerShip.cpp
//  Space Invaders
//
//  Created by Ramy Fawaz on 5/17/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
    mPosX = SCREEN_WIDTH/2 - 40;
    mPosY = SCREEN_HEIGHT - SCREEN_HEIGHT/4;
    mVelX = 0;
}

PlayerShip::PlayerShip(LTexture* shipTexture)
{
    mPosX = SCREEN_WIDTH/2 - 40;
    mPosY = SCREEN_HEIGHT - SCREEN_HEIGHT/4;
    mVelX = 0;
    setTexture(shipTexture);
}

void PlayerShip::setTexture(LTexture *shipTexture)
{
    texture = shipTexture;
}

void PlayerShip::handleEvent(SDL_Event& e)
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_LEFT: mVelX -= velocity; break;
            case SDLK_RIGHT: mVelX += velocity; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_LEFT: mVelX += velocity; break;
            case SDLK_RIGHT: mVelX -= velocity; break;
        }
    }
}

void PlayerShip::move()
{
    //Move the dot left or right
    mPosX += mVelX;
}

void PlayerShip::render()
{
    SDL_Rect* test_Rectangle = new SDL_Rect;
    test_Rectangle->x = 0;
    test_Rectangle->y = 0;
    test_Rectangle->w = 80;
    test_Rectangle->h = 40;
    
    texture->render(mPosX, mPosY,test_Rectangle);
}

PlayerShip::~PlayerShip()
{
    //Destructor
}