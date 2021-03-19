// Criado por mim (Marco Antonio) seguindo tutorial de um livro;
/*
                                    BREVE DESCRIÇÃO:
    Definição das funções do objeto GameObject. A função load pega todos os parametros necessarios
para um objeto e joga na classe criada; A função draw pega todas as informações dentro da classe e usa
o TextureManager para renderizar o objeto; A função update é responsavel por atualizar alguns dominios
da classe a fim de fazer animações e movimento(nesse exemplo o m_x é responsavel pelo movimento na di
reção x e o m_currentFrame é responsável pela a animação); o clear por enquanto não faz nada;
*/

#include "GameObject.h"


void GameObject::load(int x, int y, int width, int height, std::string textureid) 
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height =  height;
    m_textureID = textureid;

    m_currentRow = 1;
    m_currentFrame = 1;
}

void GameObject::draw(SDL_Renderer* pRenderer) 
{
    TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
}

void GameObject::update() 
{
   m_x +=1; 
   m_currentFrame = int(((SDL_GetTicks()/100)%6));
}

void GameObject::clear() 
{
    
}
