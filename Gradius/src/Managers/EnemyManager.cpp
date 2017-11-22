//
// Created by Quentin on 11/10/2017.
//

#include <iostream>

#include "../../includes/Managers/EnemyManager.h"
#include "../../includes/Managers/DisplayManager.h"

using namespace Managers;

EnemyManager::EnemyManager() : m_enemyList {}
{
    std::cout << "EnemyManager created" << std::endl;
}

EnemyManager::~EnemyManager()
{
    for (auto it : this->m_enemyList)
        delete it;

    std::cout << "EnemyManager destroyed" << std::endl;
}

void EnemyManager::Setup()
{
    for (int i = 0; i < 2; ++i)
    {
        int random = rand()%(DisplayManager::m_windowH - 150) + 150;
        this->addEnemy(new Enemy(random));
    }
}

void EnemyManager::Update(float p_elapsedTime)
{
    for (auto it : this->m_enemyList)
        it->Update(p_elapsedTime);
}

std::list<Enemy *> &EnemyManager::getEnemyList()
{
    return this->m_enemyList;
}

void EnemyManager::Display(sf::RenderWindow &p_window)
{
    for (auto it : this->m_enemyList)
        it->Display(p_window);
}

void EnemyManager::addEnemy(Enemy *p_enemy)
{
    if (p_enemy == nullptr) return;

    this->m_enemyList.push_back(p_enemy);
}

void EnemyManager::removeEnemy(Enemy *p_enemy)
{
    if (p_enemy == nullptr) return;

    std::list<Enemy*>::iterator it;

    for (it = this->m_enemyList.begin(); it != this->m_enemyList.end(); )
    {
        if ((*it) == p_enemy)
        {
            delete *it;
            it = this->m_enemyList.erase(it);
        }
        else
            ++it;
    }
}