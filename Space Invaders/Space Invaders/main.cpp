//
//  main.cpp
//  Space Invaders
//
//  Created by Ramy Fawaz on 5/17/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#include "GameManager.h"
#include <iostream>



bool init();                        //Starts up SDL and creates window
bool loadMedia();                   //Loads media

void close();                       //Frees media and shuts down SDL

//GlobalManager* GlobalManager::globalManager = nullptr;
GameManager* GameManager::gameManager = nullptr;
GameManager* mainGame;


int main( int argc, char* args[] )
{
    mainGame = GameManager::getGameManager();
    
    if( !mainGame->init() )
    {printf( "Initialization did not work properly\n" );}
    else
    {
        bool quit = false;
        SDL_Event e;
            
        while( !quit )
        {
            while( SDL_PollEvent( &e ) != 0 )
            {
                if( e.type == SDL_QUIT )
                {quit = true;}
                    
                mainGame->handleEvent(e);
            }
                
            mainGame->updatePosition();

            mainGame->clearScreen();
                
            mainGame->renderObjects();
                
            mainGame->updateScreen();
        }
        
    }
    mainGame->close();
    
    return 0;
}
