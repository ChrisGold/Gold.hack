#pragma once

#include "Action.h"
#include "../Direction.h"

class Interact : public Action {
protected:
    void execute(TickContext &ctx, Actor *executor) override;

    void write_out(std::ostream &out) const override;

public:
    Interact();

};
