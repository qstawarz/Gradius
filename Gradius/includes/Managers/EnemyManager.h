//
// Created by Quentin on 11/10/2017.
//

#ifndef GRADIUS_ENEMY_MANAGER_H
#define GRADIUS_ENEMY_MANAGER_H

#include <list>

#include "IManager.h"
#include "../Actors/Enemy.h"

using namespace Actors;

namespace Managers
{
    class EnemyManager : public IManager
    {
    private:
        std::list<Enemy*> m_enemyList;

        float m_elapsedTime;

    protected:

    public:
        EnemyManager();
        ~EnemyManager();

        void Setup() override;
        void Update() override {}
        void Update(float p_elapsedTime);

        std::list<Enemy*> &getEnemyList();

        void Display(sf::RenderWindow &p_window);

        void addEnemy(Enemy *p_enemy);
        void removeEnemy(Enemy *p_enemy);

    };
}

#endif //GRADIUS_ENEMY_MANAGER_H