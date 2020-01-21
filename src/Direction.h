#pragma once
#include <iostream>
#include <SFML/System.hpp>

enum Direction : char {
    SELF, NORTH, SOUTH, EAST, WEST
};

std::ostream &operator<<(std::ostream &out, const Direction &direction);

sf::Vector2i toVector(Direction direction);
