//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_ENEMY_H
#define GRADIUS_ENEMY_H

#include <SFML/Graphics.hpp>

#include "IActor.h"
#include "../../includes/Utils/Sprite.h"

using namespace Utils;

namespace Actors
{
    class Enemy : public IActor
    {
    private:
        Sprite *m_sprite;

        float m_speed;
        float m_scale;
        float m_waveAmplitude;
        float m_wavePeriod;
        float m_offset;

    protected:

    public:
        explicit Enemy(float offset);
        ~Enemy();

        void Setup();
        void Display(sf::RenderWindow &p_window) override;
        void Update() override {}
        void Update(float p_elapsedTime);

        sf::Sprite &getSprite() const;

    };
}

#endif //GRADIUS_ENEMY_H