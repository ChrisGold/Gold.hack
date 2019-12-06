//
// Created by christian on 04.12.19.
//

#include "Interact.h"

void Interact::write_out(std::ostream &out) const {
    out << "Interacting...";
}

void Interact::execute(Actor *executor) {

}

Interact::Interact(GamePtr game, LevelPtr level, Direction direction) : Action(game, level, direction) {

}
