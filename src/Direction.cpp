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

sf::Vector2i toVector(Direction direction) {
    sf::Vector2i vec(0, 0);
    switch (direction) {
        case SELF:
            break;
        case NORTH:
            vec.y = -1;
            break;
        case SOUTH:
            vec.y = 1;
            break;
        case EAST:
            vec.x = 1;
            break;
        case WEST:
            vec.x = -1;
            break;
    }
    return vec;
}
