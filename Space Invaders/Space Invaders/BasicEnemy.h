//
//  BasicEnemy.h
//  Space Invaders
//
//  Created by Ramy Fawaz on 6/2/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#ifndef __Space_Invaders__BasicEnemy__
#define __Space_Invaders__BasicEnemy__

#include "Enemy.h"

class BasicEnemy : public Enemy
{
public:
    BasicEnemy();
    void render();
    
    int getWidth();
    int getHeight();
    int getX();
    int getY();
private:
    int width, height;
    
};

#endif /* defined(__Space_Invaders__BasicEnemy__) */
