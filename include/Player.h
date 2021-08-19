// Criado por mim (Marco Antonio) seguindo tutorial de um livro;
/*
                                    BREVE DESCRIÇÃO:
    Classe criada com o objetivo de criar nossos players, usando uma prática de POO: a herança.
Essa Classe a principio é igual a GameObject só que com leves diferenças; Essa classe herda tudo
da classe mãe (GameObject), e sobrescreve as funções para fazer coisas diferentes;
*/
#pragma once
#ifndef PLAYER_H
#define PLAYER_H

class SDLGameObject;

#include "SDLGameObject.h"

class Player : public SDLGameObject {
public:
    Player(const LoaderParams* pParams);

    void draw();
    void update();
    void clear();
};

#endif