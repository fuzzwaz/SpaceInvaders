//
//  Enemy.h
//  Space Invaders
//
//  Created by Ramy Fawaz on 6/2/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//
#include "LTexture.h"

#ifndef __Space_Invaders__Enemy__
#define __Space_Invaders__Enemy__

class Enemy
{
public:
   void setTexture (LTexture* enemyTexture);
    void setPos(int xPosition, int yPosition);
    virtual void render() = 0;
protected:
    LTexture* texture;
    int xPos, yPos;
};

#endif /* defined(__Space_Invaders__Enemy__) */
