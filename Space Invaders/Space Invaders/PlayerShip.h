//
//  PlayerShip.h
//  Space Invaders
//
//  Created by Ramy Fawaz on 5/17/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#include "LTexture.h"

#ifndef Space_Invaders_PlayerShip_h
#define Space_Invaders_PlayerShip_h

class PlayerShip
{
public:
    PlayerShip();
    ~PlayerShip();
private:
    int lives = 3;
    LTexture* texture;
};

#endif
