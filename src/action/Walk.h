#pragma once

#include "Action.h"

class Walk : public Action {
    bool can_walk(const TickContext &ctx, sf::Vector2i from);

protected:
    void write_out(std::ostream &out) const override;

public:
    Walk(Direction direction);

    void execute(TickContext &ctx, Actor *executor) override;

    bool on_exit(const TickContext &ctx, sf::Vector2i on);
};
