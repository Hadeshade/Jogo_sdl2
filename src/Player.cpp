// Criado por mim (Marco Antonio) seguindo tutorial de um livro;
/*
                                    BREVE DESCRIÇÃO:
    As definições da funções aqui são bem semelhantes a da GameObject, porém em vez
dela armazenar as informações dentro de dominios próprios, ela usa as da classe mãe
(GameObject).
*/

#include "Player.h"
#include "Vector2D.h"

Player::Player(const LoaderParams* pParams):
    SDLGameObject(pParams)
{

}

void Player::draw() 
{
    SDLGameObject::draw();
}

void Player::update() 
{
    if(m_position.getX() > 640 || m_position.getY() > 480)
    {
        if (m_position.getX() > 640)
        {
            m_position.setX(-128);
        }
        if (m_position.getY() > 480)
        {
            m_position.setY(-82);
        }
        
    }
    
    
    m_position.setX(m_position.getX() + 1 );
    m_position.setY(m_position.getY() + 1 );
    m_accleration.setX(1);
    SDLGameObject::update();
    m_currentFrame = int(((SDL_GetTicks()/100)%6));
}

void Player::clear() 
{
    
}

