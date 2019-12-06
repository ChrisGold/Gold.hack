#pragma once

#include <SFML/Window/Event.hpp>
#include "../Types.h"

class InputController {
public:
    explicit InputController(GamePtr game);
    virtual ~InputController() = default;

    virtual Action *readInput(const sf::Event &event) = 0;

protected:
    GamePtr game;
};
