//
// Created by christian on 23.01.20.
//

#include "Fighter.h"
#include "../../level/Level.h"
#include "../Attack.h"

bool Fighter::act(TickContext &ctx) {
    auto directions = {Direction::NORTH, Direction::SOUTH, Direction::EAST, Direction::WEST};
    for (Direction d : directions) {
        auto target = ctx.level->at(position + toVector(d));
        if (target != nullptr && (dynamic_cast<Player *>(target))) {
            facing = d;
            Attack a = Attack();
            a.execute(ctx, this);
            break;
        }
    }
}

Fighter::Fighter(const std::string &name, int textureId, const sf::Vector2i &position) : Character(name, textureId,
                                                                                                   position) {}
