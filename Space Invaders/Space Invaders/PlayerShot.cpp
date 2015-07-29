//
//  PlayerShot.cpp
//  Space Invaders
//
//  Created by Ramy Fawaz on 7/24/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#include "PlayerShot.h"

PlayerShot::PlayerShot()
{
    lifeTime.start();
}

void PlayerShot::setTexture(LTexture *shotTexture)
{
    texture = shotTexture;
}

void PlayerShot::setPos(int xPosition, int yPosition)
{
    xPos = xPosition;
    yPos = yPosition;
}

void PlayerShot::render()
{
    SDL_Rect* test_Rectangle = new SDL_Rect;
    test_Rectangle->x = 0;
    test_Rectangle->y = 0;
    test_Rectangle->w = 4;
    test_Rectangle->h = 16;
    
    texture->render(xPos, yPos, test_Rectangle);
}

float PlayerShot::getTime()
{
    return (lifeTime.getTicks() / 1000);
}

int PlayerShot::getXPost()
{
    return xPos;
}

int PlayerShot::getYPos()
{
    return yPos;
}