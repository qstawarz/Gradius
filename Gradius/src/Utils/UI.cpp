//
// Created by Quentin on 11/13/2017.
//

#include <iostream>

#include "../../includes/Utils/UI.h"

using namespace Utils;

UI::UI() : m_font {nullptr}, m_text {nullptr}
{
    std::cout << "UI created" << std::endl;
}

UI::~UI()
{
    if (this->m_text != nullptr)
        delete this->m_text;

    if (this->m_font != nullptr)
        delete this->m_font;

    std::cout << "UI destroyed" << std::endl;
}

void UI::Setup()
{
    this->m_font = new sf::Font;
    this->m_text = new sf::Text;

    this->m_font->loadFromFile("../res/Fonts/gradius.ttf");
    this->m_text->setFont(*this->m_font);
    this->m_text->setFillColor(sf::Color::White);
    this->m_text->setCharacterSize(24u);
    this->m_text->setPosition(5.0f, 0.0f);
}

void UI::Update(int &p_score)
{
    this->m_text->setString("SCORE : " + std::to_string(p_score));
}

void UI::Display(sf::RenderWindow &p_window)
{
    p_window.draw(*this->m_text);
}

sf::Text &UI::getText()
{
    return *this->m_text;
}