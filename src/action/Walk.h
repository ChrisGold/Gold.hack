#pragma once

#include "Action.h"

class Walk : Action {
    void execute(Actor *executor) override;
};
