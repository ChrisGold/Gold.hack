#include "Action.h"
#include "Walk.h"
#include "Attack.h"
#include "Interact.h"

std::ostream &operator<<(std::ostream &out, const Action &action) {
    action.write_out(out);
    return out;
}

Action *Action::from(Input input) {
    switch (input) {
        case UP:
            return new Walk(Direction::NORTH);
        case DOWN:
            return new Walk(Direction::SOUTH);
        case LEFT:
            return new Walk(Direction::WEST);
        case RIGHT:
            return new Walk(Direction::EAST);
        case ACTION_1:
            return new Attack();
        case ACTION_2:
            return new Interact();
        default:
            return nullptr;
    }
}
