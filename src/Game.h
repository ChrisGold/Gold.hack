#pragma once

#include <vector>
#include <variant>
#include <SFML/Graphics/RenderWindow.hpp>

#include "level/Level.h"
#include "resources/TileSet.h"
#include "resources/TextureSet.h"
#include "input/InputController.h"
#include "action/Actor.h"

typedef std::variant<int, std::monostate> GameStage;
const GameStage MENU = std::monostate();

class Game
{
    std::vector<Level> levels;
    sf::RenderWindow window;
    GameStage stage = MENU;
    TileSet tileSet;
    TextureSet textureSet;
    InputController* inputController;

public:
    Game();
    ~Game();
    void loop();

    Level *currentLevel();

private:
    void change_stage(const GameStage &stage);
    void draw_level();

    void tick();

};

std::string stage_name(const GameStage &stage);
