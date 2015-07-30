//
//  Block.h
//  Space Invaders
//
//  Created by Ramy Fawaz on 6/4/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#ifndef __Space_Invaders__Block__
#define __Space_Invaders__Block__

#include "LTexture.h"

class Block
{
public:
    Block();
    
    
    void setTexture (LTexture* blockyTexture);
    void setPos(int xPosition, int yPosition);
    void render();
    
    int getWidth();
    int getHeight();
    int getX();
    int getY();
protected:
    LTexture* texture;
    int xPos, yPos;
    int width, height;
};

#endif /* defined(__Space_Invaders__Block__) */
