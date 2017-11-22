//
// Created by Quentin on 11/12/2017.
//

#ifndef GRADIUS_SPRITE_H
#define GRADIUS_SPRITE_H

#include <SFML/Graphics.hpp>

namespace Utils
{
    class Sprite
    {
    private:
        sf::Texture *m_texture;
        sf::Sprite *m_sprite;

    protected:

    public:
        explicit Sprite(const std::string &p_filename);
        ~Sprite();

        sf::Sprite *getSprite() const;

        void loadSprite(const std::string &p_filename);

    };
}

#endif //GRADIUS_SPRITE_H