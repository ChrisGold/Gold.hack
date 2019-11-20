#pragma once

#include "../Game.h"

enum Direction : char {
    SELF, NORTH, SOUTH, EAST, WEST
};

class Action {
    Game &game;
    Level &level;
    Direction direction = SELF;
public:
    Action(Game &game, Level &level, Direction direction);

    virtual void write_out(std::ostream &out) const = 0;

    friend std::ostream &operator<<(std::ostream &out, const Action &action);

private:
    virtual void execute(sf::Vector2i from) = 0;
};
