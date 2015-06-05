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
}

void BasicEnemy::render()
{
    SDL_Rect* test_Rectangle = new SDL_Rect;
    test_Rectangle->x = 0;
    test_Rectangle->y = 0;
    test_Rectangle->w = 48;
    test_Rectangle->h = 32;
    
    texture->render(xPos, yPos, test_Rectangle);
}