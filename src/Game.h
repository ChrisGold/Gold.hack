#ifndef GOLD_HACK_GAME_H
#define GOLD_HACK_GAME_H

#include <vector>
#include "level/Level.h"
#include <SFML/Window.hpp>
#include <variant>

typedef std::variant<int, std::monostate> GameStage;
const GameStage MENU = std::monostate();

class Game
{
    std::vector<Level<10, 10>> levels;
    sf::Window window;
    GameStage stage = MENU;

public:
    void init();
    void loop();
    
private:
    void change_stage(GameStage stage);
};

std::string stage_name(GameStage stage);

#endif //GOLD_HACK_LEVEL_H
