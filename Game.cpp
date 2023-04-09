#include "Game.h"
#include "TextureManager.h"
#include <SDL_ttf.h>
#include<iostream>
#include<cstdlib>
using namespace std;
int m_currentFrame;
Game::Game(){
    m_pWindow=NULL;
    m_pRenderer=NULL;
    isRunning=false;
}
 SDL_Texture* Game::str_to_texture(string str){
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, str.c_str(), {0,0,0} );
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(m_pRenderer,textSurface);
    mWidth=textSurface->w;
    mHeight =textSurface->h;
    SDL_FreeSurface(textSurface);
    return textTexture;
}
bool Game::gameInit(const char* title, int xpos, int ypos, int width, int height, int flags){
    Snake_block.push_back({0,0});
 // attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        cout << "SDL init success\n";
 // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(m_pWindow != 0) {// window init success

            cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
            if(m_pRenderer != 0){ // renderer init success

                cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer,255,255,255,255);
                }
            else{
                cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
        else{
            cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else{
        cout << "SDL init fail\n";
        return false; // SDL init fail
    }
    cout << "init success\n";
    isRunning = true;
    gameOver = true;
    Delay=200;
    TheTextureManager::Instance()->load("assets/snakeblock.png", "snakeblock", m_pRenderer);
    TheTextureManager::Instance()->load("assets/animation.png", "animation", m_pRenderer);
    TheTextureManager::Instance()->load("assets/apple.png", "apple", m_pRenderer);
    TTF_Init();
    gFont = TTF_OpenFont( "Raleway-Medium.ttf", 28 );
    apl.first=block_size*2;
    apl.second=block_size*2;
    return true;
}
void Game::gameRender(){
    SDL_RenderClear(m_pRenderer);
    SDL_Rect k; k.x=0; k.y=0; k.w=mWidth; k.h=mHeight;
    SDL_RenderCopy(m_pRenderer,str_to_texture("Score: "+to_string(score)),NULL,&k);
    for(int i=0;i<lengthofSnake-1;++i)
        TheTextureManager::Instance()->draw("snakeblock", Snake_block[i].first,Snake_block[i].second, block_size , block_size , m_pRenderer);
        TheTextureManager::Instance()->drawFrame("animation", Snake_block[lengthofSnake-1].first,Snake_block[lengthofSnake-1].second, block_size , block_size , 1, frame, m_pRenderer, SDL_FLIP_NONE,angle);
        TheTextureManager::Instance()->draw("apple", apl.first,apl.second, block_size , block_size , m_pRenderer);
        SDL_RenderPresent(m_pRenderer);
}
void Game::handleEvents(){
    SDL_Event event;
        if(SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    isRunning = false;
                    break;
                case SDL_KEYDOWN:{
                    switch(event.key.keysym.sym){
                        case SDLK_LEFT:
                            if(posx!=block_size){
                                posx=-block_size;
                                angle=180;}
                                posy=0;
                            break;
                        case SDLK_RIGHT:
                            if(posx!=-block_size){
                                posx=block_size;
                                angle=0;
                            }
                            posy=0;
                            break;
                        case SDLK_UP:
                            posx=0;
                            if(posy!=block_size){
                                posy=-block_size;
                                angle=270;
                            }
                            break;
                        case SDLK_DOWN:
                            posx=0;
                            if(posy!=-block_size){
                                posy=block_size;
                                angle=90;
                            }
                            break;
                        case SDLK_p:
                        gameOver=true;
                        break;
                    }
                }
            default:
            break;
            }
        }
}
void Game::gameClean(){
    cout << "cleaning game\n";
    TTF_CloseFont( gFont );
    gFont = NULL;
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}
void Game::gameUpdate(){
    frame=(int)(3*SDL_GetTicks()/Delay)%3; // 3 khung hinh
    if(SDL_GetTicks()>Mark+Delay){
        int a=Snake_block[0].first,b=Snake_block[0].second;
        if(Snake_block[lengthofSnake-1].first+posx>block_size*19){//theo chieu rong
            Snake_block[lengthofSnake-1].first=-block_size;
        }
        if(Snake_block[lengthofSnake-1].first+posx<0){
            Snake_block[lengthofSnake-1].first=block_size*20;//theo chieu rong
        }
        if(Snake_block[lengthofSnake-1].second+posy>block_size*13){//theo chieu dai
            Snake_block[lengthofSnake-1].second=-block_size;
        }
        if(Snake_block[lengthofSnake-1].second+posy<0){
            Snake_block[lengthofSnake-1].second=block_size*14;//theo chieu dai
        }
        if(Snake_block[lengthofSnake-1].first+posx!=apl.first||Snake_block[lengthofSnake-1].second+posy!=apl.second){
            for(int i=0;i<lengthofSnake-1;++i) {
                    if(Snake_block[i]==Snake_block[lengthofSnake-1]){
                        isRunning=false;
                        break;
                    }
                    Snake_block[i]=Snake_block[i+1];
            }
            Snake_block[lengthofSnake-1].first+=posx;
            Snake_block[lengthofSnake-1].second+=posy;
        }
        else{
            Snake_block.push_back({Snake_block[lengthofSnake-1].first+posx,Snake_block[lengthofSnake-1].second+posy});
            ++lengthofSnake;
            ++score;
            apl.first=(rand()%20)*block_size;// theo chieu rong
            apl.second=(rand()%14)*block_size;// theo chieu dai
            int check=true;
            while(check){
                check=false;
                for(int i=0;i<lengthofSnake;++i){
                    if(apl.first==Snake_block[i].first&&apl.second==Snake_block[i].second){
                        apl.first=(rand()%20)*block_size;
                        apl.second=(rand()%14)*block_size;
                        check=true;
                        break;
                    }
                }
            }
        }
    Mark=SDL_GetTicks();
    }
}
