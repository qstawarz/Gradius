//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H

#include "DisplayManager.h"
#include "InputManager.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "../Actors/Player.h"
#include "../Utils/UI.h"

using namespace Actors;

namespace Managers
{
    class Game : public IManager
    {
    private:
        DisplayManager *m_displayManager;
        InputManager *m_inputManager;
        EnemyManager *m_enemyManager;
        Player *m_player;
        UI *m_UI;

        sf::Clock m_clock;
        float m_elapsedTime;
        int m_score;

    protected:

    public:
        Game();
        ~Game();

        void Setup() override;
        void Update() override {}
        void Update(float p_elapsedTime);

        void Display();
        void Run();

        void addEnemy();
        void score();

        void isCollision();
    };
}

#endif //GRADIUS_GAME_H