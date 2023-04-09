#include<SDL.h>
#include"Game.h"
Game* g_game = 0;
int main(int argc, char* argv[]){
    g_game = new Game();
    g_game->gameInit("SnakeXenzia", 100, 100, 1000, 700, 0);
    while(g_game->gameIsRunning()){
        g_game->handleEvents();
        g_game->gameUpdate();
        g_game->gameRender();

    }
    g_game->gameClean();
    return 0;
}
