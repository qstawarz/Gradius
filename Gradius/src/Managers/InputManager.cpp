//
// Created by Quentin on 11/9/2017.
//

#include <iostream>

#include "../../includes/Managers/InputManager.h"

using namespace Managers;

InputManager::InputManager(sf::RenderWindow *p_window) : m_event {nullptr}, m_dir {0.0f, 0.0f},
                                                         m_window {p_window}, m_isSpace {false}
{
    std::cout << "InputManager created" << std::endl;
}

InputManager::~InputManager()
{
    if (this->m_event != nullptr)
        delete this->m_event;

    std::cout << "InputManager destroyed" << std::endl;
}

void InputManager::Setup()
{
    this->m_event = new sf::Event;
}

void InputManager::Update()
{
    this->checkInput(*this->m_window);
}

sf::Vector2f &InputManager::getDir()
{
    return this->m_dir;
}

void InputManager::checkInput(sf::RenderWindow &p_window)
{
    while (p_window.pollEvent(*this->m_event))
    {
        if (this->m_event->type == sf::Event::Closed)
            p_window.close();

        if (this->m_event->type == sf::Event::KeyPressed)
        {
            if (this->m_event->key.code == sf::Keyboard::Right ||
                this->m_event->key.code == sf::Keyboard::D)
                this->m_dir.x = 1;

            if (this->m_event->key.code == sf::Keyboard::Left ||
                this->m_event->key.code == sf::Keyboard::A)
                this->m_dir.x = -1;

            if (this->m_event->key.code == sf::Keyboard::Up ||
                this->m_event->key.code == sf::Keyboard::W)
                this->m_dir.y = -1;

            if (this->m_event->key.code == sf::Keyboard::Down ||
                this->m_event->key.code == sf::Keyboard::S)
                this->m_dir.y = 1;

            if (this->m_event->key.code == sf::Keyboard::Space)
                this->m_isSpace = true;
        }

        if (this->m_event->type == sf::Event::KeyReleased)
        {
            if (this->m_event->key.code == sf::Keyboard::Right || this->m_event->key.code == sf::Keyboard::D ||
                this->m_event->key.code == sf::Keyboard::Left || this->m_event->key.code == sf::Keyboard::A)
                this->m_dir.x = 0;

            if (this->m_event->key.code == sf::Keyboard::Up || this->m_event->key.code == sf::Keyboard::W ||
                this->m_event->key.code == sf::Keyboard::Down || this->m_event->key.code == sf::Keyboard::S)
                this->m_dir.y = 0;

            if (this->m_event->key.code == sf::Keyboard::Space)
                this->m_isSpace = false;
        }

        if (this->m_event->key.code == sf::Keyboard::Escape)
            p_window.close();
    }
}

bool InputManager::isSpace()
{
    return this->m_isSpace;
}

void InputManager::setIsSpace(bool input)
{
    this->m_isSpace = input;
}