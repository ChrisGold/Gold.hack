#pragma once

#include <SFML/Window/Event.hpp>
#include "../Types.h"

class InputController {
public:
    explicit InputController(Game *game);
    virtual ~InputController() = default;
    virtual void readInput(const sf::Event& event) = 0;
private:
    GamePtr game;
};
