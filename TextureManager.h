#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>

class TextureManager
{
private:
    std::map<std::string, SDL_Texture*> m_textureMap;
    TextureManager() {};
    static TextureManager* s_pInstance;
public:
    bool load(std::string, std::string,SDL_Renderer*);
    void draw(std::string,int,int,int,int,SDL_Renderer*,SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(std::string,int,int,int,int,int,int,SDL_Renderer*,SDL_RendererFlip flip = SDL_FLIP_NONE);
    static TextureManager* Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }

        return s_pInstance;
    }
};

typedef TextureManager TheTextureManager;










#endif