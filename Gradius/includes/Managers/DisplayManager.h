//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_DISPLAY_H
#define GRADIUS_DISPLAY_H

#include <SFML/Graphics.hpp>

#include "IManager.h"

namespace Managers
{
    class DisplayManager : public IManager
    {
    public:
        static const unsigned m_windowW = 1080;
        static const unsigned m_windowH = 720;

    private:
        sf::RenderWindow *m_window;

        bool m_isStarted;

    protected:

    public:
        DisplayManager();
        ~DisplayManager();

        void Setup() override;
        void Update() override;

        sf::RenderWindow *getWindow() const;

        bool IsRunning() const;
        bool IsStarted() const;

    };
}

#endif //GRADIUS_DISPLAY_H