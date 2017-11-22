//
// Created by Quentin on 11/9/2017.
//

#include <iostream>
#include <cmath>

#include "../../includes/Actors/Bullet.h"

using namespace Actors;

Bullet::Bullet(sf::Vector2f vector2f) : m_sprite {nullptr}, m_speed {1000.0f}, m_scale {1.5f},
                                        m_waveAmplitude {15.0f}, m_wavePeriod {0.5f}
{
    this->m_sprite = new Sprite("../res/Assets/bullet.png");

    this->m_sprite->getSprite()->setPosition(vector2f);
    this->m_sprite->getSprite()->scale(sf::Vector2f(this->m_scale, this->m_scale));

    std::cout << "Bullet created" << std::endl;
}

Bullet::~Bullet()
{
    if (this->m_sprite != nullptr)
        delete this->m_sprite;

    std::cout << "Bullet destroyed" << std::endl;
}

void Bullet::Setup()
{

}

void Bullet::Display(sf::RenderWindow &p_window)
{
    p_window.draw(*this->m_sprite->getSprite());
}

void Bullet::Update(float p_elapsedTime)
{
    static float x = 0.0f;
    float y;

    y = -this->m_waveAmplitude * std::sin(x);
    x += this->m_wavePeriod;
    this->m_sprite->getSprite()->move(this->m_speed * p_elapsedTime, y);
}

sf::Sprite &Bullet::getSprite() const
{
    return *this->m_sprite->getSprite();
}