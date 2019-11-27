#pragma once

#include "InputController.h"

class KeyboardController : public InputController{
public:
    KeyboardController(Game* game);
    ~KeyboardController() = default;

    void readInput();
};