//
//  GameManager.h
//  Space Invaders
//
//  Created by Ramy Fawaz on 5/18/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#ifndef __Space_Invaders__GameManager__
#define __Space_Invaders__GameManager__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>

class GameManager
{
public:
    GameManager();
    bool init();
private:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    
    SDL_Window* gWindow = NULL;
    SDL_Renderer* gRenderer = NULL;
};

#endif /* defined(__Space_Invaders__GameManager__) */
