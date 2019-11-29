#pragma once

#include "../Game.h"

class Actor;

class Action {
protected:
    GamePtr game;
    LevelPtr level;
    Direction direction = SELF;
public:
    Action(GamePtr game, LevelPtr level, Direction direction);

    virtual void write_out(std::ostream &out) const = 0;

    friend std::ostream &operator<<(std::ostream &out, const Action &action);

    virtual void execute(Actor *executor) = 0;
};
