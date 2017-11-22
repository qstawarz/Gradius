//
// Created by Quentin on 11/13/2017.
//

#ifndef GRADIUS_UI_H
#define GRADIUS_UI_H

#include <SFML/Graphics.hpp>

namespace Utils
{
    class UI
    {
    private:
        sf::Font *m_font;
        sf::Text *m_text;

    protected:

    public:
        UI();
        ~UI();

        void Setup();
        void Update(int &p_score);

        void Display(sf::RenderWindow &p_window);

        sf::Text &getText();

    };
}

#endif //GRADIUS_UI_H