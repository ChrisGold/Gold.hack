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
            delta.x = 1;
            break;
        case WEST:
            delta.x = -1;
            break;
    }

    int damage = 10;
    if (dynamic_cast<Player *>(executor)) {
        damage = ctx.playerInventory->currentAttack();
    }

    auto target = ctx.level->at(executor->position + delta);
    if (target != nullptr) {
        int left = target->takeDamage(damage);
        std::cout << "Hit " << target->name << " for " << damage << " HP damage, leaving " << left << "."
                  << std::endl;
    }
}

void Attack::write_out(std::ostream &out) const {
    out << "attacking";
}

Attack::Attack() = default;