//
// Created by christian on 02.01.20.
//

#include "Character.h"
#include "../Walk.h"

Character::Character(const std::string &name, std::string texture, const sf::Vector2i &position) : Actor(name, texture,
                                                                                                         position, 100) {
    facing = Direction::NORTH;
}

int Character::counter = 0;