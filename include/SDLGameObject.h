#pragma once
//#ifndef SDLGAMEOBJECT_H
//#define SDLGAMEOBJECT_H

#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject: public GameObject
{
protected:
    // int m_x;
    // int m_y;
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_accleration;

    int m_width;   
    int m_heigth;
    int m_currentRow;
    int m_currentFrame;
    std::string m_textureID;
       
public:
    SDLGameObject(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
    
};

//#endif