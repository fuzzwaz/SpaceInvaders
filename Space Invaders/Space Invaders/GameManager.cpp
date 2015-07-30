//
//  GameManager.cpp
//  Space Invaders
//
//  Created by Ramy Fawaz on 6/2/15.
//  Copyright (c) 2015 Ramy Fawaz. All rights reserved.
//


#include "GameManager.h"
#include "PlayerShot.h"
#include <iostream>

GameManager::GameManager()
{
    
    
    for (int i = 0; i < 22; i++) {
        bEnemy[i].setTexture(&enemyTexture);
    }
    
    for (int i = 0; i < 4; i++) {
        blocks[i].setTexture(&blockTexture);
    }
    
    
}

bool GameManager::init()
{
    //Initialization flag
    bool success = true;
    
    //Initialize objects in order
    mainShip = new PlayerShip();
    
    
    //Set Textures
    mainShip->setTexture(&shipTexture);
    
    
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
                
                shotTexture = new LTexture();
                
                shipTexture.setRenderer(gRenderer);
                enemyTexture.setRenderer(gRenderer);
                blockTexture.setRenderer(gRenderer);
                shotTexture->setRenderer(gRenderer);
            }
        }
    }
    
    if (success) {
        if (loadMedia())
        {
            loadLevelOne();
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    return success;
}

bool GameManager::loadMedia()
{
    //Loading success flag
    bool success = true;
    
    if( !shipTexture.loadFromFile( "player/Player_Ship.png" ) )
    {
        printf( "Failed to load ship texture!\n" );
        success = false;
    }
    
    if( !enemyTexture.loadFromFile( "enemy/Basic_Enemy.png" ) )
    {
        printf( "Failed to load basic enemy texture!\n" );
        success = false;
    }
    
    if( !blockTexture.loadFromFile( "environment/Block.png" ) )
    {
        printf( "Failed to load block texture!\n" );
        success = false;
    }
    
    if ( !shotTexture->loadFromFile( "player/Player_Shot.png" ) ) {
        printf( "Failed to load shot texture!\n" );
        success = false;
    }
    
    return success;
    
}

void GameManager::handleEvent(SDL_Event e)
{
    mainShip->handleEvent(e);
}

void GameManager::handleCEvent(CEvent e, int information)
{
    if (e == CEvent::SHOOT)
    {
        PlayerShot* newShot = new PlayerShot();
        newShot->setTexture(getShotTexture());
        newShot->setPos(mainShip->getXPos() + (mainShip->getWidth()/ 2), mainShip->getYPos() - 25);
        shots.push_back(newShot);
    }
    else if (e == CEvent::DESTROY_SHOT)
    {
        for (int i = 0; i < shots.size(); i++) {
            if (!shots[i]->isActive()) {
                delete shots[i];
                shots.erase(shots.begin() + i);
            }
        }
    }
}

void GameManager::updatePosition()
{
    mainShip->move();
    
    if (shots.size() != 0)
    {
        for (int i = 0; i < shots.size(); i++) {
            shots[i]->setPos(shots[i]->getXPos(), shots[i]->getYPos() - 8);
            shots[i]->checkTimer();
            //std::cout<<shots[i]->getXPos()<<" , "<<shots[i]->getYPos()<<std::endl;
        }
    }
}

void GameManager::renderObjects()
{
    mainShip->render();
    
    if (shots.size() != 0)
    {
        for (int i = 0; i < shots.size(); i++) {
            shots[i]->render();
        }
    }
    
    for (int i = 0; i < 22; i++) {
        bEnemy[i].render();
    }
    for (int i = 0; i < 4; i++) {
        blocks[i].render();
    }
}

void GameManager::clearScreen()
{
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
    SDL_RenderClear( gRenderer );
}

void GameManager::updateScreen()
{
    SDL_RenderPresent( gRenderer );
}

void GameManager::loadLevelOne()
{
    //Setup main player
    mainShip->setPos(SCREEN_WIDTH/2 - 40, SCREEN_HEIGHT - 50);
    
    //Set up enemies
    //------Basic Enemies----
    
    for (int i = 0; i < 11; i++) {
        bEnemy[i].setPos(150 + (i * 64), 450);
    }
    
    for (int i = 0; i < 11; i++) {
        bEnemy[11 + i].setPos(150 + (i * 64), 393);
    }
    
    //Set up environment
    int blockInitPos = SCREEN_WIDTH/2 - 185;
    int blockDiff = 225;
    blocks[0].setPos(blockInitPos, SCREEN_HEIGHT - 200);
    blocks[2].setPos(blockInitPos - blockDiff, SCREEN_HEIGHT - 200);
    blocks[1].setPos(blockInitPos + blockDiff, SCREEN_HEIGHT - 200);
    blocks[3].setPos(blockInitPos + blockDiff*2, SCREEN_HEIGHT - 200);
    
    blockRange[0] = blocks[0].getY() + blocks[0].getHeight();
    blockRange[1] = blocks[0].getY();
    
    row1Range[0] = bEnemy[0].getY() + bEnemy[0].getHeight();
    row1Range[1] = bEnemy[0].getY();
    
    row2Range[0] = bEnemy[11].getY() + bEnemy[11].getHeight();
    row2Range[1] = bEnemy[11].getY();
}

void GameManager::checkCollisions()
{
    if (shots.size() > 0)
    {
        for (int i = 0; i < shots.size(); i++) {
            if (shots[i]->getYPos() < blockRange[0] && shots[i]->getYPos() > blockRange[1])
            {
                //in collision range;
                for (int j = 0; j < 4; j++)
                {
                    int x = shots[i]->getXPos();
                    if (x > blocks[j].getX() && x < (blocks[j].getX() + blocks[j].getWidth()))
                    {
                        shots[i]->deactivateShot();
                    }
                }
            }
        }
    }
}

void GameManager::close()
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

LTexture* GameManager::getShotTexture()
{
    return shotTexture;
}

SDL_Renderer* GameManager::getRenderer()
{
    return gRenderer;
}

GameManager* GameManager::getGameManager()
{
    if (gameManager == nullptr) {
        gameManager = new GameManager();
    }
    return gameManager;
}
