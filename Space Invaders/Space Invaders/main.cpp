//
//  main.cpp
//  Space Invaders
//
//  Created by Ramy Fawaz on 5/17/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//

#include "GameManager.h"
#include "PlayerShip.h"



bool init();                        //Starts up SDL and creates window
bool loadMedia();                   //Loads media

void close();                       //Frees media and shuts down SDL


SDL_Window* gWindow = NULL;         //Main Window
SDL_Renderer* gRenderer = NULL;     //Window Renderer


LTexture shipTexture(gRenderer);  //Scene texture


int main( int argc, char* args[] )
{
    //Initializes SDL/Window/Renderer/PNG
    if( !init() )
    {printf( "Initialization did not work properly\n" );}
    else
    {
        if( !loadMedia() )
        {printf( "Failed to load media!\n" );}
        else
        {

            bool quit = false;
            SDL_Event e;
            
            PlayerShip mainShip(&shipTexture);
            
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {quit = true;}
                    
                    mainShip.handleEvent(e);
                }
                
                mainShip.move();
                
                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
                SDL_RenderClear( gRenderer );

                
                //Render ship
                mainShip.render();
                
                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}

bool init()
{
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) //Setting to 1 is for linear filtering of textures
        {
            printf( "Linear Filtering failed to be enabled" );
        }
        
        //Create window function    *window name*     *x position*             *y position*             *width*       *height*       *window flags*
        gWindow = SDL_CreateWindow( "Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window    *window*  *which renderer*   *use hardware for speed*   *sync monitor with frames*
            gRenderer = SDL_CreateRenderer( gWindow,      -1           , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF ); //Background color of renderer
                
                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
                
                shipTexture.setRenderer(gRenderer);
            }
        }
    }
    
    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;
    
    //Load arrow
    if( !shipTexture.loadFromFile( "player/Player_Ship.png" ) )
    {
        printf( "Failed to load arrow texture!\n" );
        success = false;
    }
    
    return success;
}

void close()
{
    //Free loaded images
    shipTexture.free();
    
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}