#pragma once

#include <SFML/System/Vector2.hpp>
#include "../Direction.h"
#include "../TickContext.h"
#include "../input/Input.h"

class Actor;

class Level;

class Action {
public:
    Action() = default;

    virtual ~Action() = default;

    virtual void write_out(std::ostream &out) const = 0;

    friend std::ostream &operator<<(std::ostream &out, const Action &action);

    virtual void execute(TickContext &ctx, Actor *executor) = 0;

    static Action *from(Input input);
};
