#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Vector2D.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams):
    GameObject(pParams), m_position(pParams->getX(), pParams->getY())
{
    m_width = pParams->getWidth();
    m_heigth = pParams->getHeight();
    m_textureID = pParams->getTextureID();
    m_currentFrame = 1; 
    m_currentRow = 1;
}

void SDLGameObject::draw()
{
    TextureManager::Instance()->drawFrame(m_textureID,(int)m_position.getX() ,(int)m_position.getY(),m_width,m_heigth,m_currentRow,m_currentFrame,
        TheGame::Instance()->getRenderer());
}

void SDLGameObject::update() 
{
    
}

void SDLGameObject::clean() 
{
    
}

