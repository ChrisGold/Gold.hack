#pragma once

#include "../Game.h"

class Actor;

enum Direction : char {
    SELF, NORTH, SOUTH, EAST, WEST
};

class Action {
protected:
    Game &game;
    Level &level;
    Direction direction = SELF;
public:
    Action(Game &game, Level &level, Direction direction);

    virtual void write_out(std::ostream &out) const = 0;

    friend std::ostream &operator<<(std::ostream &out, const Action &action);

    virtual void execute(Actor *executor) = 0;
};
