#include "Action.h"

Action::Action(Direction direction) : direction(direction) {}

std::ostream &operator<<(std::ostream &out, const Action &action) {
    action.write_out(out);
    return out;
}
