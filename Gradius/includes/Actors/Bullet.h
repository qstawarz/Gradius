//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_BULLET_H
#define GRADIUS_BULLET_H

#include <SFML/Graphics.hpp>

#include "IActor.h"
#include "../../includes/Utils/Sprite.h"

using namespace Utils;

namespace Actors
{
    class Bullet : public IActor
    {
    private:
        Sprite *m_sprite;

        float m_speed;
        float m_scale;
        float m_waveAmplitude;
        float m_wavePeriod;


    protected:

    public:
        explicit Bullet(sf::Vector2f vector2f);
        ~Bullet();

        void Setup() override;
        void Display(sf::RenderWindow &p_window) override;
        void Update() override {}
        void Update(float p_elapsedTime);

        sf::Sprite &getSprite() const;

    };
}

#endif //GRADIUS_BULLET_H