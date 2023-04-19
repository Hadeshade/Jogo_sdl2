// Criado por mim (Marco Antonio) seguindo tutorial de um livro;
/*
                                    BREVE DESCRIÇÃO:
    As definições da funções aqui são bem semelhantes a da GameObject, porém em vez
dela armazenar as informações dentro de dominios próprios, ela usa as da classe mãe
(GameObject).
*/

#include "Player.h"
#include "Vector2D.h"
#include "InputHandler.h"

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
    //Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
    m_currentFrame = int(((SDL_GetTicks()/100)%6));

    if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
		m_velocity = (*vec - m_position) / 100;
	}
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)){
        m_velocity.setX(2);
    }
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)){
        m_velocity.setX(-2);
    }
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)){
        m_velocity.setY(-2);
    }
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)){
        m_velocity.setY(2);
    }
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)){
        m_velocity.setY(0);
        m_velocity.setX(0);
    }    
    
    m_position.setX(m_position.getX());
    m_position.setY(m_position.getY());
    //m_velocity.setX(1);


    //m_velocity = (*vec - m_position) / 100;
    SDLGameObject::update();
    
}

void Player::clear() 
{
    
}

void Player::handleInput(){
    Vector2D* target = TheInputHandler::Instance()->getMousePosition();

    m_velocity = *target - m_position;

    m_velocity /= 50;
}

