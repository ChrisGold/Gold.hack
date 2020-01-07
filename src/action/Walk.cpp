//
// Created by y0079849 on 11/22/19.
//

#include <iostream>
#include "Walk.h"
#include "Actor.h"
#include "../Game.h"
#include "../level/Level.h"

void Walk::execute(TickContext &ctx, Actor *executor) {
    std::cout << executor->name << " walking " << direction;
    if (!can_walk(ctx, executor->position)) {
        std::cout << " ...boink" << std::endl;
        return;
    } else std::cout << std::endl;
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
    if (dynamic_cast<Player *>(executor) && on_exit(ctx, executor->position)) {
        std::cout << executor->name << " is on exit!" << std::endl;
        ctx.game->level_advance();
    }
}

void Walk::write_out(std::ostream &out) const {
    out << "walk " << direction;
}

Walk::Walk(Direction direction) : Action(direction) {

}

bool Walk::can_walk(const TickContext &ctx, sf::Vector2i from) {
    auto &tile = ctx.level->tiles[from.x][from.y];
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

bool Walk::on_exit(const TickContext &ctx, sf::Vector2i on) {
    return ctx.level->exitPosition == on;
}