//
// Created by Quentin on 11/13/2017.
//

#ifndef GRADIUS_IACTOR_H
#define GRADIUS_IACTOR_H

namespace Actors
{
    class IActor
    {
    private:

    protected:

    public:
        virtual ~IActor() {}

        virtual void Setup() = 0;
        virtual void Display(sf::RenderWindow &p_window) = 0;
        virtual void Update() = 0;

    };
}

#endif //GRADIUS_IACTOR_H