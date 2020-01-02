#pragma once

#include <SFML/System/Vector2.hpp>
#include "../Direction.h"
#include "../TickContext.h"

class Actor;

class Level;

class Action {
protected:
    Direction direction = SELF;
public:
    Action(Level *, Direction direction);

    virtual void write_out(std::ostream &out) const = 0;

    friend std::ostream &operator<<(std::ostream &out, const Action &action);

    virtual void execute(const TickContext &ctx, Actor *executor) = 0;
};
