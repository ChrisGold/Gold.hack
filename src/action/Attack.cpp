//
// Created by christian on 10.01.20.
//

#include <sstream>
#include "Attack.h"
#include "../level/Level.h"

void Attack::execute(TickContext &ctx, Actor *executor) {
    std::stringstream output;
    output << executor->name << " " << *this << " " << executor->facing << std::endl;
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
    bool isPlayer = dynamic_cast<Player *>(executor);
    if (isPlayer) {
        if (!ctx.playerInventory->useEnergy(ctx.playerInventory->currentItem().durability)) {
            ctx.messageQueue->push_back("Not enough energy.");
            return;
        }
        damage = ctx.playerInventory->currentAttack() / ctx.difficulty;
    }

    auto target = ctx.level->at(executor->position + delta);
    if (target != nullptr) {
        int left = target->takeDamage(damage);
        output << "Hit " << target->name << " for " << damage << " HP damage" << std::endl << "leaving " << left << "."
               << std::endl;
        if (isPlayer && !target->isAlive()) {
            ctx.playerInventory->addScore(target->getMaxHealth());
        }
    }
    std::cout << output.str();
    ctx.messageQueue->push_back(output.str());
}

void Attack::write_out(std::ostream &out) const {
    out << "attacking";
}

Attack::Attack() = default;