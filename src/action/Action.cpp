#include "Action.h"
#include "Actor.h"

Action::Action(GamePtr game, LevelPtr level, Direction direction) : game(game), level(level), direction(direction) {}

std::ostream &operator<<(std::ostream &out, const Action &action) {
    action.write_out(out);
    return out;
}
