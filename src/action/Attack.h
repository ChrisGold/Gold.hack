#pragma once

#include "Action.h"

class Attack : public Action {
    void write_out(std::ostream &out) const;

public:
    void execute(TickContext &ctx, Actor *executor) override;

    Attack();
};
