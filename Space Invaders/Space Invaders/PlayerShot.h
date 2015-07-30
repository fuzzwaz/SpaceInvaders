//
//  PlayerShot.h
//  Space Invaders
//
//  Created by Ramy Fawaz on 7/24/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#ifndef __Space_Invaders__PlayerShot__
#define __Space_Invaders__PlayerShot__

#include "LTexture.h"
#include "LTimer.h"

class PlayerShot
{
public:
    PlayerShot();
    void setTexture (LTexture* shotTexture);
    void setPos(int xPosition, int yPosition);
    void render();
    void checkTimer();
    void deactivateShot();
    
    bool isActive();
    int getXPos();
    int getYPos();
    float getTime();
protected:
    LTexture* texture;
    LTimer lifeTime;
    int xPos, yPos;
    bool active;
};

#endif /* defined(__Space_Invaders__PlayerShot__) */
