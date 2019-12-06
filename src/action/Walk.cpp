//
// Created by y0079849 on 11/22/19.
//

#include <iostream>
#include <utility>
#include "Walk.h"

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
    executor->facing = direction;
    executor->position += step;
}

void Walk::write_out(std::ostream &out) const {
    out << "walk " << direction;
}

Walk::Walk(GamePtr game, LevelPtr level, Direction direction) : Action(game, std::move(level), direction) {

}

bool Walk::can_walk(sf::Vector2i from) {
    auto &tile = level->tiles[from.x][from.y];
    switch (direction) {
        case SELF:
            return true;
        case NORTH:
            return tile.pass_north;
        case SOUTH:
            return tile.pass_south;
        case EAST:
            return tile.pass_east;
        case WEST:
            return tile.pass_west;
    }
}

