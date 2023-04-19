// Criado por mim (Marco Antonio) seguindo tutorial de um livro;
/*
                                    BREVE DESCRIÇÃO:
    Classe principal do jogo até então, ela é a responsável por usar todas as outras 
classes do jogo e construir o nosso jogo em si (seria tipo o responsável pelo front-end).
Nessa classe construimos o renderizador, e a janela que vai ser mostrada ao usuário, e 
nela é onde fica a função para fazer o loop do jogo funcionar(m_pRunning);
*/
#pragma once
#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "TextureManager.h"
#include "Player.h"
#include "GameObject.h"
#include "GameStateMachine.h"
#include "PlayState.h"
#include "MenuState.h"


class Game
{
private:
    SDL_Window* m_pWindow;              // Ponteiro para uma janela;
    SDL_Renderer* m_pRenderer;          // Ponteiro para renderização;

    bool m_pRunning;

    GameObject* m_go;
    GameObject* m_player;

    std::vector<GameObject*> m_gameObjects;

    GameStateMachine* m_pGameStateMachine;

    Game(){}
    static Game* s_pInstance;

    
public:
    SDL_Renderer* getRenderer() const { return m_pRenderer;}

    GameStateMachine* getStateMachine(){return m_pGameStateMachine;}

    bool init(const char*,int,int,int,int,int);
    void render();
    void update();
    void handleEvents();
    void clear();
    void quit() {m_pRunning=false;}

    bool running() {return m_pRunning;}

    static Game* Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }
};

typedef Game TheGame;


#endif