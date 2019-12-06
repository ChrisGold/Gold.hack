//
// Created by y0079849 on 12/6/19.
//

#include "Direction.h"

std::ostream &operator<<(std::ostream &out, const Direction &direction) {
    switch (direction) {
        case SELF:
            out << "themself";
            break;
        case NORTH:
            out << "north";
            break;
        case SOUTH:
            out << "south";
            break;
        case EAST:
            out << "east";
            break;
        case WEST:
            out << "west";
            break;
    }
}
