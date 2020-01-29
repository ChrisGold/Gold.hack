#include "src/Game.h"

/**
 * The main function. It takes no arguments.
 * @return 0 for normal termination, non-zero for anomalous termination.
 */
int main()
{
    auto game = std::make_shared<Game>();
    game->loop();
    return 0;
}