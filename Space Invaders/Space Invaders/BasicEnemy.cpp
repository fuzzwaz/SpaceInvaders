//
//  BasicEnemy.cpp
//  Space Invaders
//
//  Created by Ramy Fawaz on 6/2/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#include "BasicEnemy.h"

BasicEnemy::BasicEnemy()
{
    xPos = 0;
    yPos = 0;
    width = 48;
    height = 32;
}

void BasicEnemy::render()
{
    SDL_Rect* test_Rectangle = new SDL_Rect;
    test_Rectangle->x = 0;
    test_Rectangle->y = 0;
    test_Rectangle->w = width;
    test_Rectangle->h = height;
    
    texture->render(xPos, yPos, test_Rectangle);
}

int BasicEnemy::getWidth()
{
    return width;
}

int BasicEnemy::getHeight()
{
    return height;
}

int BasicEnemy::getX()
{
    return xPos;
}

int BasicEnemy::getY()
{
    return yPos;
}