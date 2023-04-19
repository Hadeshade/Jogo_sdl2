#include "PlayState.h"
#include "Game.h"
#include <iostream>
#include <vector>

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
    for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void PlayState::render(){
    for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool PlayState::onEnter()
{
    if(!TheTextureManager::Instance()->load("img/helicopter.png", "helicopter", TheGame::Instance()->getRenderer())){
        
        return false;
    }
    GameObject* player = new Player(new LoaderParams(100,100,128,55,"helicopter"));

    m_gameObjects.push_back(player);

    std::cout << "entering PlayState\n";
    return true;
}

bool PlayState::onExit()
{
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++){
        m_gameObjects[i]->clear();
    }

    m_gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("helicopter");

    std::cout << "exiting PlayState\n";
    return true;
}