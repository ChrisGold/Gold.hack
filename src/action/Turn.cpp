//
// Created by christian on 22.01.20.
//

#include "Turn.h"

Turn::Turn(Direction direction) : direction(direction) {

}

void Turn::execute(TickContext &ctx, Actor *executor) {
    std::cout << executor->name << " turning " << direction << std::endl;
    executor->facing = direction;
}

void Turn::write_out(std::ostream &out) const {
    out << "turns " << direction;
}
