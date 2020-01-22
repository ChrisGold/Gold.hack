#pragma once

#include <SFML/Window/Keyboard.hpp>
#include "InputController.h"
#include "Keymap.h"

class KeyboardController : public InputController{

public:
    explicit KeyboardController(Game *game);
    ~KeyboardController() override = default;

    std::optional<Input> readInput(const sf::Event &event) override;
};