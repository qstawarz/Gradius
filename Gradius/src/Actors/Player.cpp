//
// Created by Quentin on 11/9/2017.
//
#include <iostream>

#include "../../includes/Managers/DisplayManager.h"
#include "../../includes/Actors/Player.h"

using namespace Actors;
using namespace Managers;

Player::Player() : m_bulletManager {nullptr}, m_sprite {nullptr}, m_speed {500.0f}, m_scale {3.0f}
{
    std::cout << "Player created" << std::endl;
}

Player::~Player()
{
    if (this->m_sprite != nullptr)
        delete this->m_sprite;

    if (this->m_bulletManager != nullptr)
        delete this->m_bulletManager;

    std::cout << "Player destroyed" << std::endl;
}

void Player::Setup()
{
    this->m_bulletManager = new BulletManager;
    this->m_sprite = new Sprite("../res/Assets/player.png");

    if (this->m_bulletManager != nullptr)
        this->m_bulletManager->Setup();

    this->m_sprite->getSprite()->setPosition(sf::Vector2f(0.0f, DisplayManager::m_windowH / 2 - this->m_sprite->getSprite()->getTextureRect().height / 2));
    this->m_sprite->getSprite()->scale(sf::Vector2f(this->m_scale, this->m_scale));
}

void Player::Display(sf::RenderWindow &p_window)
{
    this->m_bulletManager->Display(p_window);

    p_window.draw(*this->m_sprite->getSprite());
}

void Player::Update(InputManager &p_event, float p_elapsedTime)
{
    this->shoot(p_event);
    this->m_bulletManager->Update(p_elapsedTime);

    if (this->m_sprite->getSprite()->getPosition().x <= 0)
        this->m_sprite->getSprite()->move(1.0f, 0.0f);

    if (this->m_sprite->getSprite()->getPosition().x >= DisplayManager::m_windowW - this->m_sprite->getSprite()->getTextureRect().width * this->m_scale)
        this->m_sprite->getSprite()->move(-1.0f, 0.0f);

    if (this->m_sprite->getSprite()->getPosition().y <= 0)
        this->m_sprite->getSprite()->move(0.0f, 1.0f);

    if (this->m_sprite->getSprite()->getPosition().y >= DisplayManager::m_windowH - this->m_sprite->getSprite()->getTextureRect().height * this->m_scale)
        this->m_sprite->getSprite()->move(0.0f, -1.0f);

    if (this->m_sprite->getSprite()->getPosition().x > 0 &&
            this->m_sprite->getSprite()->getTextureRect().width * this->m_scale <
                    DisplayManager::m_windowW - this->m_sprite->getSprite()->getTextureRect().width * this->m_scale &&
        this->m_sprite->getSprite()->getPosition().y > 0 &&
            this->m_sprite->getSprite()->getTextureRect().height * this->m_scale <
                    DisplayManager::m_windowH - this->m_sprite->getSprite()->getTextureRect().height * this->m_scale)
        this->m_sprite->getSprite()->move(p_event.getDir().x * this->m_speed * p_elapsedTime,
                                          p_event.getDir().y * this->m_speed * p_elapsedTime);
}

void Player::shoot(InputManager &p_event)
{
    sf::Vector2f vector2f;

    vector2f.x = this->m_sprite->getSprite()->getPosition().x +
                (this->m_sprite->getSprite()->getTextureRect().width / 2) * this->m_scale;
    vector2f.y = this->m_sprite->getSprite()->getPosition().y +
                (this->m_sprite->getSprite()->getTextureRect().height / 2) * this->m_scale;

    if (p_event.isSpace())
        this->m_bulletManager->addBullet(new Bullet(vector2f));

    p_event.setIsSpace(false);
}

BulletManager &Player::getBulletManager()
{
    return *this->m_bulletManager;
}
