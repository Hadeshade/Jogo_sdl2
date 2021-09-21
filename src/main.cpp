// Criado por mim (Marco Antonio) seguindo tutorial de um livro;
/*
                                    BREVE DESCRIÇÃO:
    A main do jogo inteiro. Ela não tem nenhuma responsabilidade além do loop principal
e chamar a classe Game que da vida ao jogo inteiro;
*/
#include <iostream>
#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main()
{
    Uint32 frameStart, frameTime;
    std::cout << "Game init attempt...\n";
    //g_game->init("Chapter 1", 100, 100, 640, 480, 0);
    if (TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, 0))
    {
        std::cout << "game init success!\n";
        while (TheGame::Instance()->running())
        {
            frameStart = SDL_GetTicks();

            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            frameTime = SDL_GetTicks() - frameStart;

            if (frameTime < DELAY_TIME)
            {
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
            
        }   
    }
    else
    {
        std::cout << "game init failure - " << SDL_GetError() << "\n";
        return -1;
    }
    std::cout << "game closing...\n";
    TheGame::Instance()->clear();
    
    return 0;
}