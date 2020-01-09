#pragma once

#include <vector>
#include <variant>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "level/Level.h"
#include "resources/TileSet.h"
#include "resources/TextureSet.h"
#include "input/InputController.h"
#include "action/Actor.h"
#include "Menu.h"
#include "inventory/Inventory.h"
#include "resources/Fonts.h"
#include "resources/Resources.h"

typedef std::variant<int, std::monostate> GameStage;
const GameStage MENU = std::monostate();

class Game {
    std::vector<Level> levels;
    Menu menu;

    sf::RenderWindow window;

    sf::Sprite levelSprite;
    sf::RenderTexture levelTexture;

    sf::Sprite sidebarSprite;
    sf::RenderTexture sidebarTexture;


    GameStage stage = MENU;
    Resources resources;
    InputController *inputController;
    Inventory *playerInventory;

    long tick_count;
public:
    Game();

    ~Game();

    void loop();

    Level *currentLevel();

    void level_advance();

private:
    void change_stage(const GameStage &stage);

    void draw_level();

    void tick();

    void level_loop(sf::Clock &clock);

    void menu_loop();

    void menu_input(sf::Event event);

    void level_input(sf::Event event);
};

std::string stage_name(const GameStage &stage);
