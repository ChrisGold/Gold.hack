#pragma once

#include "../Types.h"

class InputController {
public:
    InputController(Game *game);

private:
    GamePtr game;
};
