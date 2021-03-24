// Criado por mim (Marco Antonio) seguindo tutorial de um livro;
/*
                                    BREVE DESCRIÇÃO:
    Nesse arquivo foi declarado a classe GameObject, que vai ser a responsável por criar novas
entidades para o jogo, seja inimigos, players ou NPC ele tem a estrutura básica de um objeto a 
ser usado no jogo; 
*/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <SDL2/SDL.h>
#include "TextureManager.h"

class GameObject
{
public:
    virtual void load(int x, int y, int width, int height, std::string textureid);
    virtual void draw(SDL_Renderer* pRenderer);
    virtual void update();
    virtual void clear();
protected:
    std::string m_textureID;

    int m_currentFrame;
    int m_currentRow;

    int m_x;
    int m_y;

    int m_width;
    int m_height;
};


#endif