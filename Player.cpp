// Criado por mim (Marco Antonio) seguindo tutorial de um livro;
/*
                                    BREVE DESCRIÇÃO:
    As definições da funções aqui são bem semelhantes a da GameObject, porém em vez
dela armazenar as informações dentro de dominios próprios, ela usa as da classe mãe
(GameObject).
*/

#include "Player.h"

void Player::load(int x, int y, int width, int height, std::string textureid) 
{
    GameObject::load(x,y,width,height,textureid);
}

void Player::draw(SDL_Renderer* pRenderer) 
{
    GameObject::draw(pRenderer);
}

void Player::update() 
{
    m_x -=1;
    m_currentFrame = int(((SDL_GetTicks()/100)%6));
}

void Player::clear() 
{
    
}

