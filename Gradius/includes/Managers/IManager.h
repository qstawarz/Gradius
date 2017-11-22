//
// Created by Quentin on 11/12/2017.
//

#ifndef GRADIUS_IMANAGER_H
#define GRADIUS_IMANAGER_H

namespace Managers
{
    class IManager
    {
    private:

    protected:

    public:
        virtual ~IManager() {}

        virtual void Setup() = 0;
        virtual void Update() = 0;

    };
}

#endif //GRADIUS_IMANAGER_H