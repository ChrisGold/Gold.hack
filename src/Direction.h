#pragma once
#include <iostream>

enum Direction : char {
    SELF, NORTH, SOUTH, EAST, WEST
};

std::ostream &operator<<(std::ostream &out, const Direction &direction);
