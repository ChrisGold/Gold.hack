#pragma once

#include "Action.h"

class Walk : public Action {
protected:
    void execute(Actor *executor) override;

    void write_out(std::ostream &out) const override;

public:
    explicit Walk(Game *game, Level *level, Direction direction);
};
