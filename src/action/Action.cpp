#include "Action.h"

Action::Action(Level *level, Direction direction) : level(level), direction(direction) {}

std::ostream &operator<<(std::ostream &out, const Action &action) {
    action.write_out(out);
    return out;
}
