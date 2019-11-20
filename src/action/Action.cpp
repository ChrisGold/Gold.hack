#include "Action.h"

Action::Action(Game &game, Level &level, Direction direction) : game(game), level(level), direction(direction) {}

std::ostream &operator<<(std::ostream &out, const Action &action) {
    action.write_out(out);
    return out;
}
