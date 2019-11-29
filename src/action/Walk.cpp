//
// Created by y0079849 on 11/22/19.
//

#include "Walk.h"
#include "Actor.h"

void Walk::execute(Actor *executor) {
    sf::Vector2i step{0, 0};
    switch (direction) {
        case SELF:
            break;
        case NORTH:
            step.y = -1;
            break;
        case SOUTH:
            step.y = 1;
            break;
        case EAST:
            step.x = 1;
            break;
        case WEST:
            step.x = -1;
            break;
    }
    executor->position += step;
}

void Walk::write_out(std::ostream &out) const {
    out << "walk " << direction;
}

Walk::Walk(Game *game, Level *level, Direction direction) : Action(game, level, direction) {

}

