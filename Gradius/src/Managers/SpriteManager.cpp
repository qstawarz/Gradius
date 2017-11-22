//
// Created by Quentin on 11/12/2017.
//

#include <iostream>

#include "../../includes/Managers/SpriteManager.h"

Managers::SpriteManager::SpriteManager() : m_spriteList {}
{
    std::cout << "SpriteManager created" << std::endl;
}

Managers::SpriteManager::~SpriteManager()
{
    for (auto it : this->m_spriteList)
        delete it.second;

    std::cout << "SpriteManager destroyed" << std::endl;
}

void Managers::SpriteManager::Setup()
{
    this->m_spriteList[Layers::ENEMY] = new Sprite("../res/Assets/enemy.png");
    this->m_spriteList[Layers::PLAYER] = new Sprite("../res/Assets/player.png");
    this->m_spriteList[Layers::BULLET] = new Sprite("../res/Assets/bullet.png");
}

void Managers::SpriteManager::Update()
{

}

std::map<Managers::SpriteManager::Layers, Sprite *> &Managers::SpriteManager::getSpriteList()
{
    return this->m_spriteList;
}