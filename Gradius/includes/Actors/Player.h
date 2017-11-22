//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_PLAYER_H
#define GRADIUS_PLAYER_H

#include <SFML/Graphics.hpp>

#include "IActor.h"
#include "../Managers/InputManager.h"
#include "../Managers/BulletManager.h"
#include "../../includes/Utils/Sprite.h"

using namespace Utils;
using namespace Managers;

namespace Actors
{
    class Player : public IActor
    {
    private:
        BulletManager *m_bulletManager;

        Sprite *m_sprite;

        float m_speed;
        float m_scale;

    protected:

    public:
        Player();
        ~Player();

        void Setup();
        void Display(sf::RenderWindow &p_window) override;
        void Update() override {}
        void Update(InputManager &p_event, float p_elapsedTime);

        void shoot(InputManager &p_event);

        BulletManager &getBulletManager();

    };
}

#endif //GRADIUS_PLAYER_H