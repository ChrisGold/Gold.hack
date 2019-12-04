//
// Created by y0079849 on 11/22/19.
//

#include <iostream>
#include "Walk.h"
#include "Actor.h"

void Walk::execute(Actor *executor) {
    if (!can_walk(executor->position)) {
        std::cout << "boink" << std::endl;
        return;
    }
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

bool Walk::can_walk(sf::Vector2i from) {
    switch (direction) {
        case SELF:
            return true;
        case NORTH:
            return level->tiles[from.x][from.y].pass_north;
        case SOUTH:
            return level->tiles[from.x][from.y + 1].pass_north;
        case EAST:
            return level->tiles[from.x][from.y].pass_east;
        case WEST:
            return level->tiles[from.x - 1][from.y].pass_east;
    }
}

