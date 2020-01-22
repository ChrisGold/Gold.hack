#include "Action.h"
#include "Walk.h"
#include "Attack.h"
#include "Interact.h"
#include "Turn.h"

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
        case TURN_UP:
            return new Turn(Direction::NORTH);
        case TURN_DOWN: //for what?
            return new Turn(Direction::SOUTH);
        case TURN_LEFT:
            return new Turn(Direction::WEST);
        case TURN_RIGHT:
            return new Turn(Direction::EAST);
        case ACTION_1:
            return new Attack();
        case ACTION_2:
            return new Interact();
        default:
            return nullptr;
    }
}
