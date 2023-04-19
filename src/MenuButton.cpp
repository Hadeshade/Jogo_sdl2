#include "MenuButton.h"
#include "InputHandler.h"
#include "Game.h"

MenuButton::MenuButton(const LoaderParams* pParams, void (*callback)()): SDLGameObject(pParams), m_callback(callback){
    m_currentFrame = MOUSE_OUT; // começa no frame 0
}

void MenuButton::draw(){
    SDLGameObject::draw(); //usando a classe base para desenhar na tela
}

void MenuButton::update(){
    Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

    if(pMousePos->getX() < (m_position.getX() + m_width)
    && pMousePos->getX() > m_position.getX()
    && pMousePos->getY() < (m_position.getY() + m_heigth)
    && pMousePos->getY() > m_position.getY())
    {
        if(TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased){
            m_currentFrame = CLICKED;

            m_callback(); // chamada da função de callback
            
            m_bReleased = false;
        }
        else if(!TheInputHandler::Instance()->getMouseButtonState(LEFT)){
            m_bReleased = true;
            m_currentFrame = MOUSE_OVER;
        }
    }
    else{
        m_currentFrame = MOUSE_OUT;
    }
}

void MenuButton::clear(){
    SDLGameObject::clean();
}