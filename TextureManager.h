#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include<string>
#include<SDL.h>
#include<map>
#include <iostream>
using namespace std;
class TextureManager{

    public:
        static TextureManager* Instance(){
            if(s_pInstance == 0){
                s_pInstance = new TextureManager();
            }
            return s_pInstance;
        }

        bool load(string fileName,string id, SDL_Renderer* pRenderer);
        void draw(string id,int x,int y,int width,int height,SDL_Renderer* pRenderer,SDL_RendererFlip flip = SDL_FLIP_NONE);
        void drawFrame(string id,int x,int y,int width,int height,int currentRow,int currentFrame,SDL_Renderer* pRenderer,SDL_RendererFlip flip=SDL_FLIP_NONE,double angle=0);
    private:
        static TextureManager* s_pInstance;
        TextureManager(){};
        ~TextureManager(){};
        map<string, SDL_Texture*> m_textureMap;
};
typedef TextureManager TheTextureManager;
#endif // TEXTUREMANAGER_H
