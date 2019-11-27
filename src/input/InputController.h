#pragma once

#include "../Types.h"

class InputController {
public:
    explicit InputController(Game *game);
    ~InputController() = default;
    virtual void readInput() = 0;
private:
    GamePtr game;
};
