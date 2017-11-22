//
// Created by Quentin on 11/12/2017.
//

#ifndef GRADIUS_SPRITEMANAGER_H
#define GRADIUS_SPRITEMANAGER_H

#include <map>

#include "IManager.h"
#include "../Utils/Sprite.h"

using namespace Utils;

namespace Managers
{
    class SpriteManager : public IManager
    {
    public:
        enum class Layers : uint8_t
        {
            BACKGROUND = 0u,
            PLAYER,
            ENEMY,
            BULLET,
            UI
        };

    private:
        std::map<Layers, Sprite*> m_spriteList;

    protected:

    public:
        SpriteManager();
        ~SpriteManager();

        void Setup() override;
        void Update() override;

        std::map<Layers, Sprite*> &getSpriteList();
    };
}

#endif //GRADIUS_SPRITEMANAGER_H