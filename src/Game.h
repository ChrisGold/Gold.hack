#pragma once

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "level/Level.h"
#include "input/InputController.h"
#include "action/Actor.h"
#include "Menu.h"
#include "inventory/Inventory.h"
#include "GameStage.h"
#include "resources/Resources.h"

/**
 * The main Game object. This keeps track of all objects that can only exist centrally.
 */
class Game {
    std::vector<Level> levels;
    Menu menu;

    /**
     * The main window.
     */
    sf::RenderWindow window;

    /**
     * The sprite representing the level, later drawn into the main window.
     */
    sf::Sprite levelSprite;
    /**
     * The sf::RenderTexture into which the level is drawn.
     */
    sf::RenderTexture levelTexture;
    /**
     * The sprite representing the sidebar with the player inventory, later drawn into the main window.
     */
    sf::Sprite sidebarSprite;
    /**
    * The sf::RenderTexture into which the inventory sidebar is drawn.
    */
    sf::RenderTexture sidebarTexture;


    GameStage stage = MENU;
    Resources resources;
    InputController *inputController;
    Inventory *playerInventory;

    long tick_count;
    float difficulty;
public:
    Game();

    ~Game();

    void loop();

    Level *currentLevel();

    void level_advance();

    void game_over();

private:
    void change_stage(const GameStage &stage);

    void draw_level();

    void tick();

    void menu_input(sf::Event event);

    void level_input(sf::Event event);

};

std::string stage_name(const GameStage &stage);
