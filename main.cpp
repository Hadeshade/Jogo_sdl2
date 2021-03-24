// Criado por mim (Marco Antonio) seguindo tutorial de um livro;
/*
                                    BREVE DESCRIÇÃO:
    A main do jogo inteiro. Ela não tem nenhuma responsabilidade além do loop principal
e chamar a classe Game que da vida ao jogo inteiro;
*/
#include <iostream>
#include "Game.h"

Game* g_game = 0;

int main()
{
    g_game = new Game();

    g_game->init("Chapter 1", 100, 100, 640, 480, 0);

    while (g_game->running())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();

        SDL_Delay(10);          // adiciona um delay;
    }
    g_game->clear();

    return 0;
}