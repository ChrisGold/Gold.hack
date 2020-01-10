#pragma once

#include "Action.h"

class Attack : public Action {
    void execute(TickContext &ctx, Actor *executor) override;

    void write_out(std::ostream &out) const;

public:
    Attack(Direction direction);
};
