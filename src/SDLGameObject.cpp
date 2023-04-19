#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Vector2D.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams):
    GameObject(pParams), m_position(pParams->getX(), pParams->getY()), m_velocity(0,0), m_accleration(0,0)
{
    m_width = pParams->getWidth();
    m_heigth = pParams->getHeight();
    m_textureID = pParams->getTextureID();
    m_currentFrame = 1; 
    m_currentRow = 1;
}

void SDLGameObject::draw()
{
    if(m_velocity.getX() > 0){
        TextureManager::Instance()->drawFrame(m_textureID,(Uint32)m_position.getX() ,(Uint32)m_position.getY(),m_width,m_heigth,m_currentRow,m_currentFrame,
        TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
    }
    else{
        TextureManager::Instance()->drawFrame(m_textureID,(Uint32)m_position.getX() ,(Uint32)m_position.getY(),m_width,m_heigth,m_currentRow,m_currentFrame,
        TheGame::Instance()->getRenderer());
    }

}

void SDLGameObject::update() 
{
   m_velocity += m_accleration;
   m_position += m_velocity;
}

void SDLGameObject::clean() 
{
    
}

