#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Game{
    public:
        Game();
        ~Game();
        bool gameInit(const char* title, int xpos, int ypos, int width, int height, int flags);
        void gameRender();
        void gameUpdate();
        void handleEvents();
        SDL_Texture* str_to_texture(string str);
        SDL_Texture* str_to_texture2(string str);
        void gameClean();
        bool gameIsRunning() { return isRunning; }

    private:
        const int block_size=50;
        double angle=0;
        int score=0;
        int Delay,Mark=0;
        int frame=0;
        int x=0,y=0,mWidth,mHeight;
        int length=1;
        vector<pair<int,int>> Snake;
        pair<int,int> apl;
        TTF_Font *Font;
        int posx=0,posy=0;
        SDL_Window* gameWindow;
        SDL_Renderer* gameRenderer;
        bool isRunning,gameOver, isMenu, mouseIn1, mouseIn2;
};

#endif // GAME_H

