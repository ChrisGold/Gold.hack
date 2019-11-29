#include <sstream>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Game.h"
#include "input/KeyboardController.h"

Game::Game()
{
    window.create(sf::VideoMode(LEVEL_WIDTH, LEVEL_HEIGHT), "Gold.hack");
    change_stage(0);
    tileSet = TileSet::init();
    textureSet = TextureSet::init();
    levels = Level::make(this);
    inputController = new KeyboardController(this);
}

Game::~Game() {
    delete inputController;
}

void Game::loop()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        if (clock.getElapsedTime().asMilliseconds() > MS_PER_TICK) {
            tick();
            clock.restart();
        }
        window.clear(sf::Color::White);
        if(stage != MENU){
            draw_level();
        }

        sf::Event event{};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            auto action = inputController->readInput(event);
            if (action != nullptr) {
                currentLevel()->enqueue(action);
            }
        }
        window.display();
    }
}

void Game::draw_level(){
    int stage_id = std::get<int>(stage);
    Level &level = levels[stage_id];
    level.draw(window, tileSet, textureSet);
}

void Game::change_stage(const GameStage &gs) {
    window.setTitle(stage_name(gs));
    stage = gs;
}

void Game::tick() {
    currentLevel()->tick();
}

LevelPtr Game::currentLevel() {
    if (stage == MENU) {
        return nullptr;
    } else {
        return &levels[std::get<int>(stage)];
    }
}

std::string stage_name(const GameStage &stage)
{
    if (stage == MENU)
    {
        return std::string("Gold.hack: Menu");
    }
    else
    {
        std::ostringstream ss;
        ss << "Gold.hack: Level ";
        ss << std::get<int>(stage);
        return ss.str();
    }
}