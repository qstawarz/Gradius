//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_EVENT_H
#define GRADIUS_EVENT_H

#include <SFML/Graphics.hpp>

#include "IManager.h"

namespace Managers
{
    class InputManager : public IManager
    {
    private:
        sf::Event *m_event;
        sf::Vector2f m_dir;

        sf::RenderWindow *m_window;

        bool m_isSpace;

    protected:

    public:
        explicit InputManager(sf::RenderWindow *p_window);
        ~InputManager();

        void Setup() override;
        void Update() override;

        sf::Vector2f &getDir();

        void checkInput(sf::RenderWindow &p_window);

        bool isSpace();
        void setIsSpace(bool input);

    };
}

#endif //GRADIUS_EVENT_H