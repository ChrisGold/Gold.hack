#include <sstream>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Game.h"
#include "input/KeyboardController.h"
#include "resources/Config.h"

Game::Game() {
    window.create(sf::VideoMode(TOTAL_WIDTH, TOTAL_HEIGHT), "Gold.hack");

    levelTexture.create(LEVEL_WIDTH, TOTAL_HEIGHT);
    sidebarTexture.create(SIDEBAR_WIDTH, TOTAL_HEIGHT);
    levelSprite = sf::Sprite(levelTexture.getTexture());
    sidebarSprite = sf::Sprite(sidebarTexture.getTexture());
    sidebarSprite.setPosition(LEVEL_WIDTH, 0);

    auto cfg = Config::loadFromYAML("Gold.hack.yml");
    resources = cfg.loadResources();

    levels = cfg.generateLevels();
    inputController = new KeyboardController(this);
    playerInventory = new Inventory(cfg.playerName);

    tick_count = 0;
    change_stage(MENU);
}

Game::~Game() {
    delete inputController;
}

void Game::loop() {
    sf::Clock clock;
    while (window.isOpen()) {
        if (stage != MENU) {
            window.clear(sf::Color::White);
            draw_level();
        } else {
            menu.draw(window, resources);
        }
        if (clock.getElapsedTime().asMilliseconds() > MS_PER_TICK) {
            tick();
            clock.restart();
        }
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

void Game::level_input(sf::Event event) {
    auto inputOpt = inputController->readInput(event);
    if (inputOpt) {
        auto input = inputOpt.value();
        if (isGameAction(input)) {
            auto action = Action::from(input);
            this->currentLevel()->player->enqueue(action);
        }
    }
}

void Game::menu_input(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Button::Left) {
            menu.click(event.mouseButton.x, event.mouseButton.y);
        }
    }
}

void Game::draw_level() {
    int stage_id = std::get<int>(stage);
    auto &level = levels[stage_id];
    levelTexture.clear(sf::Color::Black);
    sidebarTexture.clear(sf::Color(128, 128, 128));

    level.draw(levelTexture, resources);
    playerInventory->draw(sidebarTexture, resources);
    sidebarTexture.display();
    levelTexture.display();

    window.draw(levelSprite);
    window.draw(sidebarSprite);
}

void Game::change_stage(const GameStage &gs) {
    window.setTitle(stage_name(gs));
    stage = gs;
}

void Game::tick() {
    TickContext ctx = TickContext(this, currentLevel(), playerInventory, tick_count, time(0));
    if (stage == MENU) {
        menu.tick(ctx);
    } else {
        currentLevel()->tick(ctx);
    }
    tick_count++;
}

Level *Game::currentLevel() {
    if (stage == MENU) {
        return nullptr;
    } else {
        return &levels[std::get<int>(stage)];
    }
}

void Game::level_advance() {
    if (stage == MENU) {
        stage = 0;
    } else {
        stage = std::get<int>(stage) + 1;
        if (std::get<int>(stage) >= levels.size()) {
            //You won the game!
            stage = MENU;
            window.close();
        }
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