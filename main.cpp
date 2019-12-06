#include "src/Game.h"

int main()
{
    auto game = std::make_shared<Game>();
    game->loop();
    return 0;
}