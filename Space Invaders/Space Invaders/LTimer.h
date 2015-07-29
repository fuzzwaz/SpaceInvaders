//
//  LTimer.h
//  Space Invaders
//
//  Created by Ramy Fawaz on 7/28/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#ifndef __Space_Invaders__LTimer__
#define __Space_Invaders__LTimer__

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
//#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>

class LTimer
{
public:
    //Initializes variables
    LTimer();
    
    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();
    
    //Gets the timer's time
    Uint32 getTicks();
    
    //Checks the status of the timer
    bool isStarted();
    bool isPaused();
    
private:
    //The clock time when the timer started
    Uint32 mStartTicks;
    
    //The ticks stored when the timer was paused
    Uint32 mPausedTicks;
    
    //The timer status
    bool mPaused;
    bool mStarted;
};

#endif /* defined(__Space_Invaders__LTimer__) */
