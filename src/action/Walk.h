#pragma once

#include "Action.h"

class Walk : public Action {
    bool can_walk(sf::Vector2i from);
protected:
    void execute(Actor *executor) override;

    void write_out(std::ostream &out) const override;

public:
    explicit Walk(GamePtr game, LevelPtr level, Direction direction);
};
