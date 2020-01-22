#pragma once

#include "../Direction.h"
#include "../TickContext.h"
#include "Actor.h"

class Turn : public Action {
    Direction direction;

    void execute(TickContext &ctx, Actor *executor) override;

    void write_out(std::ostream &out) const override;

public:
    Turn(Direction direction);
};
