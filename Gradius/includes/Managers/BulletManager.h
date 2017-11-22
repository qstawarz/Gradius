//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_BULLET_MANAGER_H
#define GRADIUS_BULLET_MANAGER_H

#include <list>

#include "IManager.h"
#include "../Actors/Bullet.h"

using namespace Actors;

namespace Managers
{
    class BulletManager : public IManager
    {
    private:
        std::list<Bullet*> m_bulletList;

    protected:

    public:
        BulletManager();
        ~BulletManager();

        void Setup() override;
        void Update() override {}
        void Update(float p_elapsedTime);

        std::list<Bullet*> &getBulletList();

        void Display(sf::RenderWindow &p_window);

        void addBullet(Bullet *p_bullet);
        void removeBullet(Bullet *p_bullet);

    };
}

#endif //GRADIUS_BULLET_MANAGER_H