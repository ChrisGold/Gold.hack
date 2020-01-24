#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <vector>

enum Direction : char {
    SELF, NORTH, SOUTH, EAST, WEST
};

const std::vector<Direction> ALL_DIRECTIONS = {Direction::NORTH, Direction::SOUTH, Direction::EAST, Direction::WEST};

std::ostream &operator<<(std::ostream &out, const Direction &direction);

sf::Vector2i toVector(Direction direction);
