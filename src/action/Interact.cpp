//
// Created by christian on 04.12.19.
//

#include <sstream>
#include "Interact.h"
#include "Actor.h"
#include "character/Player.h"

void Interact::write_out(std::ostream &out) const {
    out << "Interacting...";
}

void Interact::execute(TickContext &ctx, Actor *executor) {
    Player *player = dynamic_cast<Player *>(executor);
    if (player) {
        int hp = ctx.playerInventory->currentAttack();
        if (hp < 0 && player->getHealth() != player->getMaxHealth()) {
            player->takeDamage(hp);
            std::stringstream output;
            output << player->getName() << " healed by " << -hp << " hp." << std::endl;
            ctx.messageQueue->push_back(output.str());
        }
    }
}

Interact::Interact() : Action() {

}
