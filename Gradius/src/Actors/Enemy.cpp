//
// Created by Quentin on 11/9/2017.
//

#include <iostream>
#include <cmath>

#include "../../includes/Managers/DisplayManager.h"
#include "../../includes/Actors/Enemy.h"

using namespace Actors;
using namespace Managers;

Enemy::Enemy(float offset) : m_sprite {}, m_speed {150.0f}, m_scale {3.0f},
                             m_waveAmplitude {5.0f}, m_wavePeriod {0.1f}, m_offset {offset}
{
    this->m_sprite = new Sprite("../res/Assets/enemy.png");

    this->m_sprite->getSprite()->setPosition(sf::Vector2f(DisplayManager::m_windowW - this->m_sprite->getSprite()->getTextureRect().width / 2,
                                                          this->m_offset - this->m_sprite->getSprite()->getTextureRect().height / 2));
    this->m_sprite->getSprite()->scale(sf::Vector2f(this->m_scale, this->m_scale));

    std::cout << "Enemy created" << std::endl;
}

Enemy::~Enemy()
{
    if (this->m_sprite != nullptr)
        delete this->m_sprite;

    std::cout << "Enemy destroyed" << std::endl;
}

void Enemy::Setup()
{

}

void Enemy::Display(sf::RenderWindow &p_window)
{
    p_window.draw(*this->m_sprite->getSprite());
}

void Enemy::Update(float p_elapsedTime)
{
    this->m_sprite->getSprite()->rotate(10);

    if (this->m_sprite->getSprite()->getPosition().x <= 0)
        this->m_sprite->getSprite()->setPosition(sf::Vector2f(DisplayManager::m_windowW - this->m_sprite->getSprite()->getTextureRect().width / 2,
                                                              this->m_sprite->getSprite()->getPosition().y));

    static float x = 0.0f;
    float y;

    y = -this->m_waveAmplitude * std::sin((x - this->m_offset * 2) + this->m_offset);
    x -= this->m_wavePeriod;
    this->m_sprite->getSprite()->move(-this->m_speed * p_elapsedTime, y);
}

sf::Sprite &Enemy::getSprite() const
{
    return *this->m_sprite->getSprite();
}