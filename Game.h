// Criado por mim (Marco Antonio) seguindo tutorial de um livro;
/*
                                    BREVE DESCRIÇÃO:
    Classe principal do jogo até então, ela é a responsável por usar todas as outras 
classes do jogo e construir o nosso jogo em si (seria tipo o responsável pelo front-end).
Nessa classe construimos o renderizador, e a janela que vai ser mostrada ao usuário, e 
nela é onde fica a função para fazer o loop do jogo funcionar(m_pRunning);
*/
#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include "TextureManager.h"
#include "Player.h"
#include "GameObject.h"

class Game
{
private:
    SDL_Window* m_pWindow;              // Ponteiro para uma janela;
    SDL_Renderer* m_pRenderer;          // Ponteiro para renderização;

    bool m_pRunning;

    GameObject m_go;
    Player m_player;
public:
    Game(/* args */);
    ~Game();

    bool init(const char*,int,int,int,int,int);
    void render();
    void update();
    void handleEvents();
    void clear();

    bool running() {return m_pRunning;}
};



#endif