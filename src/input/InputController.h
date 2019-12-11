#pragma once

#include <SFML/Window/Event.hpp>

class Game;

class Action;

class InputController {
public:
    explicit InputController(Game *game);
    virtual ~InputController() = default;

    virtual Action *readInput(const sf::Event &event) = 0;

protected:
    Game *game;
};
