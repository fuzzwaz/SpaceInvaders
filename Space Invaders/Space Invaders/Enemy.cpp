//
//  Enemy.cpp
//  Space Invaders
//
//  Created by Ramy Fawaz on 6/2/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#include "Enemy.h"

void Enemy::setTexture(LTexture* enemyTexture)
{
    texture = enemyTexture;
}

void Enemy::setPos(int xPosition, int yPosition)
{
    xPos = xPosition;
    yPos = yPosition;
}