#pragma once

#include "Action.h"

class Walk : public Action {
    bool can_walk(const TickContext &ctx, sf::Vector2i from);

protected:
    void write_out(std::ostream &out) const override;

public:
    Walk(Direction direction);

    void execute(const TickContext &ctx, Actor *executor) override;
};
