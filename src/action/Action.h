#pragma once

#include "../Game.h"
#include "../Direction.h"

class Actor;

class Action {
protected:
    Level *level;
    Direction direction = SELF;
public:
    Action(Level *, Direction direction);

    virtual void write_out(std::ostream &out) const = 0;

    friend std::ostream &operator<<(std::ostream &out, const Action &action);

    virtual void execute(Actor *executor) = 0;
};
