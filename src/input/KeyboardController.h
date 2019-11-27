#pragma once

#include <SFML/Window/Keyboard.hpp>
#include "InputController.h"
#include "Keymap.h"

class KeyboardController : public InputController{

public:
    explicit KeyboardController(Game* game);
    ~KeyboardController() override = default;

    void readInput(const sf::Event& event) override;
};