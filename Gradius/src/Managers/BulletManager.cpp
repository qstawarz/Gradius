//
// Created by Quentin on 11/9/2017.
//

#include <iostream>

#include "../../includes/Managers/BulletManager.h"
#include "../../includes/Managers/DisplayManager.h"

using namespace Managers;

BulletManager::BulletManager() : m_bulletList {}
{
    std::cout << "BulletManager created" << std::endl;
}

BulletManager::~BulletManager()
{
    for (auto it : this->m_bulletList)
        delete it;

    std::cout << "BulletManager destroyed" << std::endl;
}

void BulletManager::Setup()
{

}

void BulletManager::Update(float p_elapsedTime)
{
    for (auto it : this->m_bulletList)
    {
        if (it->getSprite().getPosition().x > DisplayManager::m_windowW)
            this->removeBullet(it);
        it->Update(p_elapsedTime);
    }
}

std::list<Bullet *> &BulletManager::getBulletList()
{
    return this->m_bulletList;
}

void BulletManager::Display(sf::RenderWindow &p_window)
{
    for (auto it : this->m_bulletList)
        it->Display(p_window);
}

void BulletManager::addBullet(Bullet *p_bullet)
{
    if (p_bullet == nullptr) return;

    this->m_bulletList.push_back(p_bullet);
}

void BulletManager::removeBullet(Bullet *p_bullet)
{
    if (p_bullet == nullptr) return;

    std::list<Bullet*>::iterator it;

    for (it = this->m_bulletList.begin(); it != this->m_bulletList.end(); )
    {
        if ((*it) == p_bullet)
        {
            delete *it;
            it = this->m_bulletList.erase(it);
        }
        else
            ++it;
    }
}