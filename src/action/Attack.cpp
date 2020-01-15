//
// Created by christian on 10.01.20.
//

#include "Attack.h"
#include "../level/Level.h"

void Attack::execute(TickContext &ctx, Actor *executor) {
    std::cout << executor->name << " " << *this << " " << executor->facing << std::endl;
    sf::Vector2i delta;
    switch (executor->facing) {
        case NORTH:
            delta.y = -1;
            break;
        case SOUTH:
            delta.y = 1;
            break;
        case EAST:
            delta.x = -1;
            break;
        case WEST:
            delta.x = 1;
            break;
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
    out << "attacking";
}

Attack::Attack(Direction direction) : Action(direction) {

}
