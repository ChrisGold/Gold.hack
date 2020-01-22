#pragma once

#include <SFML/Window/Event.hpp>
#include <optional>
#include "Input.h"

class Game;

class Action;

class InputController {
public:
    explicit InputController(Game *game);

    virtual ~InputController() = default;

    virtual std::optional<Input> readInput(const sf::Event &event) = 0;

protected:
    Game *game;
};
