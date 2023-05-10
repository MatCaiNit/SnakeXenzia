#include "Game.h"
#include "TextureManager.h"
#include <SDL_ttf.h>
#include<iostream>
#include<cstdlib>

#define SCREEN_WIDTH  1000
#define SCREEN_HEIGHT 700
using namespace std;
/*void gameOver(SDL_Renderer* renderer, SDL_Event event, int scale, int wScale, int tailLength) {
	SDL_Color Red = { 255, 0, 0 };
	SDL_Color White = { 255, 255, 255 };
	SDL_Color Black = { 0, 0, 0 };

	// Get the font used for displaying text
	TTF_Font* font = TTF_OpenFont((char*)"arial.ttf", 10);
	if (font == NULL) {
		cout << "Font loading error" << endl;
		return;
	}

	SDL_Surface* gameover = TTF_RenderText_Solid(font, "Game Over", Red);
	SDL_Surface* retry = TTF_RenderText_Solid(font, "Press Enter to retry", White);
	SDL_Surface* score = TTF_RenderText_Solid(font, (string("Score: ") + to_string(tailLength * 10)).c_str(), Black);
	SDL_Texture* gameoverMessage = SDL_CreateTextureFromSurface(renderer, gameover);
	SDL_Texture* retryMessage = SDL_CreateTextureFromSurface(renderer, retry);
	SDL_Texture* scoreMessage = SDL_CreateTextureFromSurface(renderer, score);
	SDL_Rect gameoverRect;
	SDL_Rect retryRect;
	SDL_Rect scoreRect;
	gameoverRect.w = 200;
	gameoverRect.h = 100;
	gameoverRect.x = ((scale*wScale) / 2)-(gameoverRect.w/2);
	gameoverRect.y = ((scale*wScale) / 2)-(gameoverRect.h/2)-50;
	retryRect.w = 300;
	retryRect.h = 50;
	retryRect.x = ((scale*wScale) / 2) - ((retryRect.w / 2));
	retryRect.y = (((scale*wScale) / 2) - ((retryRect.h / 2))+150);
	scoreRect.w = 100;
	scoreRect.h = 30;
	scoreRect.x = ((scale*wScale) / 2) - (scoreRect.w / 2);
	scoreRect.y = 0;
	SDL_RenderCopy(renderer, gameoverMessage, NULL, &gameoverRect);
	SDL_RenderCopy(renderer, retryMessage, NULL, &retryRect);
	SDL_RenderCopy(renderer, scoreMessage, NULL, &scoreRect);

	TTF_CloseFont(font);

	// Show game over screen while space has not been pressed
	while (true) {
		SDL_RenderPresent(renderer);

		if (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				exit(0);
			}

			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				return;
			}

		}

	}

}

void youWin(SDL_Renderer* renderer, SDL_Event event, int scale, int wScale, int tailLength) {
	SDL_Color Red = { 255, 0, 0 };
	SDL_Color White = { 255, 255, 255 };
	SDL_Color Black = { 0, 0, 0 };
	SDL_Color Yellow = { 255, 255, 0 };

	// Get the font used for displaying text
	TTF_Font* font = TTF_OpenFont((char*)"arial.ttf", 10);
	if (font == NULL) {
		cout << "Font loading error" << endl;
		return;
	}

	SDL_Surface* gameover = TTF_RenderText_Solid(font, "You won!", Yellow);
	SDL_Surface* retry = TTF_RenderText_Solid(font, "Press Enter to play again", White);
	SDL_Surface* score = TTF_RenderText_Solid(font, (string("Score: ") + to_string(tailLength * 10)).c_str(), Black);
	SDL_Texture* gameoverMessage = SDL_CreateTextureFromSurface(renderer, gameover);
	SDL_Texture* retryMessage = SDL_CreateTextureFromSurface(renderer, retry);
	SDL_Texture* scoreMessage = SDL_CreateTextureFromSurface(renderer, score);
	SDL_Rect gameoverRect;
	SDL_Rect retryRect;
	SDL_Rect scoreRect;
	gameoverRect.w = 200;
	gameoverRect.h = 100;
	gameoverRect.x = ((scale*wScale) / 2) - (gameoverRect.w / 2);
	gameoverRect.y = ((scale*wScale) / 2) - (gameoverRect.h / 2) - 50;
	retryRect.w = 300;
	retryRect.h = 50;
	retryRect.x = ((scale*wScale) / 2) - ((retryRect.w / 2));
	retryRect.y = (((scale*wScale) / 2) - ((retryRect.h / 2)) + 150);
	scoreRect.w = 100;
	scoreRect.h = 30;
	scoreRect.x = ((scale*wScale) / 2) - (scoreRect.w / 2);
	scoreRect.y = 0;
	SDL_RenderCopy(renderer, gameoverMessage, NULL, &gameoverRect);
	SDL_RenderCopy(renderer, retryMessage, NULL, &retryRect);
	SDL_RenderCopy(renderer, scoreMessage, NULL, &scoreRect);

	TTF_CloseFont(font);

	// Show victory screen while space has not been pressed
	while (true) {
		SDL_RenderPresent(renderer);

		if (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				exit(0);
			}

			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				return;
			}

		}

	}

}
*/

Game::Game(){
    gameWindow=NULL;
    gameRenderer=NULL;
    isRunning=false;
}
 SDL_Texture* Game::str_to_texture(string str){
    if(gameOver == false && mouseIn1 == false){
    SDL_Surface* textSurface = TTF_RenderText_Solid( Font, str.c_str(), {0,0,0} );
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(gameRenderer,textSurface);
    mWidth=textSurface->w;
    mHeight =textSurface->h;
    SDL_FreeSurface(textSurface);
    return textTexture;}
    if(gameOver== false && mouseIn1 == true){
    SDL_Surface* textSurface = TTF_RenderText_Solid( Font, str.c_str(), {255,0,0} );
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(gameRenderer,textSurface);
    mWidth=textSurface->w;
    mHeight =textSurface->h;
    SDL_FreeSurface(textSurface);
    return textTexture;}
    if(gameOver){
    SDL_Surface* textSurface = TTF_RenderText_Solid( Font, str.c_str(), {0,0,0} );
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(gameRenderer,textSurface);
    mWidth=textSurface->w;
    mHeight =textSurface->h;
    SDL_FreeSurface(textSurface);
    return textTexture;}

}
SDL_Texture* Game::str_to_texture2(string str){
    if(gameOver == false && mouseIn2 == false){
    SDL_Surface* textSurface2 = TTF_RenderText_Solid( Font, str.c_str(), {0,0,0} );
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(gameRenderer,textSurface2);
    mWidth=textSurface2->w;
    mHeight =textSurface2->h;
    SDL_FreeSurface(textSurface2);
    return textTexture2;}
    if(gameOver== false && mouseIn2 == true){
    SDL_Surface* textSurface2 = TTF_RenderText_Solid( Font, str.c_str(), {255,0,0} );
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(gameRenderer,textSurface2);
    mWidth=textSurface2->w;
    mHeight =textSurface2->h;
    SDL_FreeSurface(textSurface2);
    return textTexture2;}
    if(gameOver){
    SDL_Surface* textSurface2 = TTF_RenderText_Solid( Font, str.c_str(), {0,0,0} );
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(gameRenderer,textSurface2);
    mWidth=textSurface2->w;
    mHeight =textSurface2->h;
    SDL_FreeSurface(textSurface2);
    return textTexture2;}

}
bool Game::gameInit(const char* title, int xpos, int ypos, int width, int height, int flags){
    Snake.push_back({200,300});
    mWidth = width;
    mHeight = height;

 // attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        cout << "SDL init success\n";
 // init the window
        gameWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(gameWindow != 0) {// window init success

            cout << "window creation success\n";
            gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);
            if(gameRenderer != 0){ // renderer init success

                cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
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
    gameOver = false;
    isMenu = true;
    mouseIn1 = false;
    mouseIn2 = false;
    Delay=200;
    TheTextureManager::Instance()->load("assets/snakeblock.png", "snakeblock", gameRenderer);
    TheTextureManager::Instance()->load("assets/animation.png", "animation", gameRenderer);
    TheTextureManager::Instance()->load("assets/apple.png", "apple", gameRenderer);
    TheTextureManager::Instance()->load("assets/gameover.jpg", "gameover", gameRenderer);
    TheTextureManager::Instance()->load("assets/backgroundsnake.jpg", "backgroundsnake", gameRenderer);
    TTF_Init();
    Font = TTF_OpenFont( "arial.ttf", 50 );
    apl.first=block_size*2;
    apl.second=block_size*2;
    return true;
}
void Game::gameRender(){
    SDL_RenderClear(gameRenderer);
    if(gameOver == false && isMenu == true){
        TheTextureManager::Instance()->draw("backgroundsnake", 0,0, SCREEN_WIDTH , SCREEN_HEIGHT , gameRenderer);
        SDL_Rect start; start.x=100; start.y=100; start.w=mWidth; start.h=mHeight;
        SDL_RenderCopy(gameRenderer,str_to_texture("Start "),NULL,&start);
        SDL_Rect exit; exit.x=100; exit.y=150; exit.w=mWidth; exit.h=mHeight;
        SDL_RenderCopy(gameRenderer,str_to_texture2("Exit "),NULL,&exit);

    }
    if(gameOver== false && isMenu == false){
        SDL_Rect k; k.x=0; k.y=0; k.w=mWidth; k.h=mHeight;
        SDL_RenderCopy(gameRenderer,str_to_texture2("Score: "+to_string(score)),NULL,&k);
        for(int i=0;i<length-1;++i){
            TheTextureManager::Instance()->draw("snakeblock", Snake[i].first,Snake[i].second, block_size , block_size , gameRenderer);
        }
        TheTextureManager::Instance()->drawFrame("animation", Snake[length-1].first,Snake[length-1].second, block_size , block_size , 1, frame, gameRenderer, SDL_FLIP_NONE,angle);
        TheTextureManager::Instance()->draw("apple", apl.first,apl.second, block_size , block_size , gameRenderer);

    } if(gameOver == true && isMenu == false){

        TheTextureManager::Instance()->draw("gameover", 0,0, SCREEN_WIDTH , SCREEN_HEIGHT , gameRenderer);
        SDL_Rect exit; exit.x=250; exit.y=600; exit.w=mWidth; exit.h=mHeight;
        //cout<<mWidth<<" "<<mHeight<<endl;

        SDL_RenderCopy(gameRenderer,str_to_texture("-Press Space to exit- "),NULL,&exit);


    }
    SDL_RenderPresent(gameRenderer);

}
void Game::handleEvents(){
    if(gameOver == false && isMenu == false){
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
    }else if(gameOver == false && isMenu == true){
        SDL_Event event;
        if(SDL_PollEvent(&event)){
            if(event.button.x >= 100 && event.button.x <=186 && event.button.y >= 100 && event.button.y <= 150){ mouseIn1 = true;}
            else if(event.button.x >= 100 && event.button.x <=186 && event.button.y >= 150 && event.button.y <= 200){ mouseIn2 = true;}
            else{mouseIn1 = false;
                mouseIn2 = false;
                }
             switch (event.type){
                 case SDL_QUIT:
                        isRunning = false;
                        break;
                 case SDL_MOUSEBUTTONDOWN:
                     if(event.button.x >= 100 && event.button.x <=186 && event.button.y >= 100 && event.button.y <= 150){ isMenu = false;}
                     if(event.button.x >= 100 && event.button.x <=186 && event.button.y >= 150 && event.button.y <= 200){
                            isRunning = false;
                           // gameOver = true;
                     }
                        break;
                 default:
                    break;
             }

        }
    }
    else{
        SDL_Event event;
            if(SDL_PollEvent(&event)){
                switch (event.type){
                    case SDL_QUIT:
                        isRunning = false;
                        break;
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym){
                            case SDLK_SPACE:
                                isRunning = false;
                                break;
                            default:
                            break;
                        }
                    }
                }
            }

}
void Game::gameClean(){
    cout << "cleaning game\n";
    TTF_CloseFont( Font );
    Font = NULL;
    TTF_Quit();
    SDL_DestroyWindow(gameWindow);
    SDL_DestroyRenderer(gameRenderer);
    SDL_Quit();
}
void Game::gameUpdate(){
    if(gameOver){

    }else{
        frame=(int)(6*SDL_GetTicks()/Delay)%6;
        if(SDL_GetTicks()>Mark+Delay){
            int a=Snake[0].first,b=Snake[0].second;
            if(Snake[length-1].first+posx>block_size*19){
                Snake[length-1].first=-block_size;
            }
            if(Snake[length-1].first+posx<0){
                Snake[length-1].first=block_size*20;
            }
            if(Snake[length-1].second+posy>block_size*13){
                Snake[length-1].second=-block_size;
            }
            if(Snake[length-1].second+posy<0){
                Snake[length-1].second=block_size*14;
            }
            if(Snake[length-1].first+posx!=apl.first||Snake[length-1].second+posy!=apl.second){
                for(int i=0;i<length-1;++i) {
                        if(Snake[i]==Snake[length-1]){
                            //isRunning=false;
                            gameOver=true;
                            break;
                        }
                        Snake[i]=Snake[i+1];
                }
                Snake[length-1].first+=posx;
                Snake[length-1].second+=posy;
            }
            else{
                Snake.push_back({Snake[length-1].first+posx,Snake[length-1].second+posy});
                ++length;
                ++score;
                apl.first=(rand()%20)*block_size;
                apl.second=(rand()%14)*block_size;
                int check=true;
                while(check){
                    check=false;
                    for(int i=0;i<length;++i){
                        if(apl.first==Snake[i].first&&apl.second==Snake[i].second){
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
}
