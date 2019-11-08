#pragma once

#include <vector>
#include <variant>
#include <SFML/Graphics/RenderWindow.hpp>

#include "level/Level.h"
#include "resources/TileSet.h"

typedef std::variant<int, std::monostate> GameStage;
const GameStage MENU = std::monostate();

class Game
{
    std::vector<Level> levels;
    sf::RenderWindow window;
    GameStage stage = MENU;
    TileSet tileSet;

public:
    void init();
    void loop();
    
private:
    void change_stage(GameStage stage);
};

std::string stage_name(GameStage stage);
