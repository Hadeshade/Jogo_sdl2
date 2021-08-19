// Criado por mim (Marco Antonio) seguindo tutorial de um livro;
/*
                                    BREVE DESCRIÇÃO:
    A main do jogo inteiro. Ela não tem nenhuma responsabilidade além do loop principal
e chamar a classe Game que da vida ao jogo inteiro;
*/
#include <iostream>
#include "Game.h"

int main()
{
std::cout << "Game init attempt...\n";
    //g_game->init("Chapter 1", 100, 100, 640, 480, 0);
    if (TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, 0))
    {
        std::cout << "game init success!\n";
        while (TheGame::Instance()->running())
        {
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            SDL_Delay(10);          // adiciona um delay;
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