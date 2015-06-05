//
//  Block.cpp
//  Space Invaders
//
//  Created by Ramy Fawaz on 6/4/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#include "Block.h"


Block::Block()
{
    texture = NULL;
    xPos = 0;
    yPos = 0;
}

void Block::setTexture(LTexture *blockyTexture)
{
    texture = blockyTexture;
}

void Block::setPos(int xPosition, int yPosition)
{
    xPos = xPosition;
    yPos = yPosition;
}

void Block::render()
{
    SDL_Rect* test_Rectangle = new SDL_Rect;
    test_Rectangle->x = 0;
    test_Rectangle->y = 0;
    test_Rectangle->w = 144;
    test_Rectangle->h = 108;
    
    texture->render(xPos, yPos, test_Rectangle);
}