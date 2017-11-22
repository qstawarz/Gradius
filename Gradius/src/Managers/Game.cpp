//
// Created by Quentin on 11/9/2017.
//
#include <iostream>
#include <ctime>

#include "../../includes/Managers/Game.h"

using namespace Managers;

Game::Game() : m_displayManager {nullptr}, /*m_spriteManager {nullptr},*/ m_inputManager {nullptr},
               m_enemyManager {nullptr}, m_player {nullptr}, m_UI {nullptr}, m_elapsedTime {0}, m_score {0}
{
    std::cout << "Game created" << std::endl;
}

Game::~Game()
{
    if (this->m_UI != nullptr)
        delete this->m_UI;

    if (this->m_player != nullptr)
        delete this->m_player;

    if (this->m_enemyManager != nullptr)
        delete this->m_enemyManager;

    if (this->m_inputManager != nullptr)
        delete this->m_inputManager;

    if (this->m_displayManager != nullptr)
        delete this->m_displayManager;

    std::cout << "Game destroyed" << std::endl;
}

void Game::Setup()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    this->m_displayManager = new DisplayManager();

    if (this->m_displayManager != nullptr)
        this->m_displayManager->Setup();

    if (this->m_displayManager->IsStarted())
        this->m_inputManager = new InputManager(this->m_displayManager->getWindow());

    this->m_enemyManager = new EnemyManager();
    this->m_player = new Player();
    this->m_UI = new UI();

    if (this->m_inputManager != nullptr)
        this->m_inputManager->Setup();

    if (this->m_enemyManager != nullptr)
        this->m_enemyManager->Setup();

    if (this->m_player != nullptr)
        this->m_player->Setup();

    if (this->m_UI != nullptr)
        this->m_UI->Setup();
}

void Game::Update(float p_elapsedTime)
{
    this->m_displayManager->Update();

    this->m_inputManager->Update();

    this->m_enemyManager->Update(p_elapsedTime);

    this->m_player->Update(*this->m_inputManager, p_elapsedTime);

    this->m_UI->Update(this->m_score);

    this->addEnemy();
    this->isCollision();
    //this->score();
}

void Game::Display()
{
    this->m_enemyManager->Display(*this->m_displayManager->getWindow());

    this->m_player->Display(*this->m_displayManager->getWindow());

    this->m_UI->Display(*this->m_displayManager->getWindow());

    this->m_displayManager->getWindow()->display();
}

void Game::Run()
{
    while (this->m_displayManager->IsRunning())
    {
        this->Update(this->m_elapsedTime);

        this->Display();

        this->m_elapsedTime = this->m_clock.getElapsedTime().asSeconds();
        this->m_clock.restart();
    }
}

void Game::addEnemy()
{
    static time_t last_time = time(nullptr);
    static int rand1 = rand()%(DisplayManager::m_windowH - 150) + 150;
    static int rand2 = rand()%10 + 1;

    if (time(nullptr) - last_time >= 1.0)
    {
        for (int i = 0; i < rand2; ++i)
            this->m_enemyManager->addEnemy(new Enemy(rand1));

        last_time = time(nullptr);
        rand1 = rand()%(DisplayManager::m_windowW - 150) + 150;
        rand2 = rand()%10 + 1;
    }
}
//TODO Score decrement too fast
void Game::score()
{
    for (auto it : this->m_enemyManager->getEnemyList())
    {
        if (it->getSprite().getPosition().x < 0.0f)
            this->m_score -= 100;
    }
}
//TODO Score increment too fast
void Game::isCollision()
{
    bool isCollision;

    auto it1 = this->m_player->getBulletManager().getBulletList().begin();
    auto it2 = this->m_enemyManager->getEnemyList().begin();

    while (it1 != this->m_player->getBulletManager().getBulletList().end())
    {
        while (it2 != this->m_enemyManager->getEnemyList().end())
        {
            isCollision = (*it1)->getSprite().getGlobalBounds().intersects((*it2)->getSprite().getGlobalBounds());

            if (isCollision)
            {
                this->m_player->getBulletManager().removeBullet(*it1);
                this->m_enemyManager->getEnemyList().remove(*it2);
                this->m_score += 50;
            }
            ++it2;
        }
        ++it1;
    }
}