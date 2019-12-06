#pragma once

#include "Action.h"

class Interact : public Action {
protected:
    void execute(Actor *executor) override;

    void write_out(std::ostream &out) const override;

public:
    explicit Interact(Game *game, LevelPtr level, Direction direction);
};
