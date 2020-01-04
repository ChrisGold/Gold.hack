#include <sstream>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Game.h"
#include "input/KeyboardController.h"
#include "TickContext.h"

Game::Game() {
    window.create(sf::VideoMode(LEVEL_WIDTH, LEVEL_HEIGHT), "Gold.hack");
    change_stage(0);
    tileSet = TileSet::init();
    textureSet = TextureSet::init();
    levels = Level::make();
    inputController = new KeyboardController(this);
    tick_count = 0;
}

Game::~Game() {
    delete inputController;
}

void Game::loop() {
    sf::Clock clock;
    while (window.isOpen()) {
        if (stage != MENU) {
            level_loop(clock);
        } else menu_loop();
        window.display();

        sf::Event event{};
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
                //TODO: Handle GainFocus and LostFocus
            else if (stage == MENU) {
                menu_input(event);
            } else level_input(event);

        }
    }
}

void Game::level_loop(sf::Clock &clock) {
    if (clock.getElapsedTime().asMilliseconds() > MS_PER_TICK) {
        tick();
        clock.restart();
    }
    window.clear(sf::Color::White);
    draw_level();
}

void Game::level_input(sf::Event event) {
    auto action = inputController->readInput(event);
    if (action != nullptr) {
        currentLevel()->enqueue(action);
    }
}

void Game::menu_loop() {
    menu.draw(window, tileSet, textureSet);
}

void Game::menu_input(sf::Event event) {

}

void Game::draw_level() {
    int stage_id = std::get<int>(stage);
    auto &level = levels[stage_id];
    level.draw(window, tileSet, textureSet);
}

void Game::change_stage(const GameStage &gs) {
    window.setTitle(stage_name(gs));
    stage = gs;
}

void Game::tick() {
    TickContext ctx = TickContext(this, currentLevel(), tick_count, time(0));
    currentLevel()->tick(ctx);
    tick_count++;
}

Level *Game::currentLevel() {
    if (stage == MENU) {
        return nullptr;
    } else {
        return &levels[std::get<int>(stage)];
    }
}

std::string stage_name(const GameStage &stage) {
    if (stage == MENU) {
        return std::string("Gold.hack: Menu");
    } else {
        std::ostringstream ss;
        ss << "Gold.hack: Level ";
        ss << std::get<int>(stage);
        return ss.str();
    }
}