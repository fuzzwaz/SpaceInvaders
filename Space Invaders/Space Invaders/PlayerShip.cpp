//
//  PlayerShip.cpp
//  Space Invaders
//
//  Created by Ramy Fawaz on 5/17/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#include "PlayerShip.h"
#include "PlayerShot.h"
#include "GameManager.h"

PlayerShip::PlayerShip()
{
    mPosX = SCREEN_WIDTH/2 - 40;
    mPosY = SCREEN_HEIGHT - SCREEN_HEIGHT/4;
    mVelX = 0;
    
    setGameManager(GameManager::getGameManager());
}

PlayerShip::PlayerShip(LTexture* shipTexture)
{
    mPosX = SCREEN_WIDTH/2 - 40;
    mPosY = SCREEN_HEIGHT - SCREEN_HEIGHT/4;
    mVelX = 0;
    setTexture(shipTexture);
}

void PlayerShip::setPos(int xPos, int yPos)
{
    mPosX = xPos;
    mPosY = yPos;
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
            case SDLK_a: mVelX -= velocity; break;
            case SDLK_d: mVelX += velocity; break;
            case SDLK_SPACE:
                gameManager->handleCEvent(CEvent::SHOOT);
                break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )         {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_LEFT: mVelX += velocity; break;
            case SDLK_RIGHT: mVelX -= velocity; break;
            case SDLK_a: mVelX += velocity; break;
            case SDLK_d: mVelX -= velocity; break;
        }
    }
}

void PlayerShip::move()
{
    //Move the ship left or right
    mPosX += mVelX;
    
}

void PlayerShip::render()
{
    SDL_Rect* test_Rectangle = new SDL_Rect;
    test_Rectangle->x = 0;
    test_Rectangle->y = 0;
    test_Rectangle->w = shipWidth;
    test_Rectangle->h = shipHeight;
    
    texture->render(mPosX, mPosY,test_Rectangle);
}

void PlayerShip::setGameManager(GameManager* thisGM)
{
    gameManager = thisGM;
}

GameManager* PlayerShip::getGameManager()
{
    return gameManager;
}

int PlayerShip::getHeight()
{
    return shipHeight;
}

int PlayerShip::getWidth()
{
    return shipWidth;
}

int PlayerShip::getXPos()
{
    return mPosX;
}

int PlayerShip::getYPos()
{
    return mPosY;
}

PlayerShip::~PlayerShip()
{
    //Destructor
}