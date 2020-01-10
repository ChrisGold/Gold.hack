//
// Created by christian on 10.01.20.
//

#include "Attack.h"
#include "../level/Level.h"

void Attack::execute(TickContext &ctx, Actor *executor) {
    sf::Vector2i delta;
    switch (executor->facing) {
        case NORTH:
            delta.y = -1;
        case SOUTH:
            delta.y = 1;
        case EAST:
            delta.x = -1;
        case WEST:
            delta.x = 1;
    }
    sf::Vector2i target = executor->position + delta;
    auto &npcs = ctx.level->npcs;
    auto it = std::find_if(npcs.begin(), npcs.end(),
                           [target](Actor *a) { return a->position == target; });
    if (it != npcs.end()) {
        npcs.erase(it);
    }
}

void Attack::write_out(std::ostream &out) const {
    out << "Attacking...";
}

Attack::Attack(Direction direction) : Action(direction) {

}
