#ifndef GOLD_HACK_GAME_H
#define GOLD_HACK_GAME_H

#include <vector>
#include "Level.h"
#include <SFML/Window.hpp>

class Game
{
    std::vector<Level<10, 10>> levels;
    sf::Window window;

public:
    void init();
    void loop();
};

#endif //GOLD_HACK_LEVEL_H
