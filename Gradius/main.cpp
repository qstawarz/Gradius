#include "includes/Managers/Game.h"

int main()
{
    using namespace Managers;
    Game game;

    game.Setup();
    game.Run();

    return 0;
}