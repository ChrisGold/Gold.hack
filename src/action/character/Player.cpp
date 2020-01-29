//
// Created by christian on 06.01.20.
//

#include "Player.h"

Player::Player(const std::string &name, std::string texture, const sf::Vector2i &position) : Actor(name, texture,
                                                                                                   position, 100) {}

std::string Player::getTexture() const {
    switch (facing) {
        case SELF:
        case NORTH:
            return texture + "_n";
        case SOUTH:
            return texture + "_s";
        case EAST:
            return texture + "_e";
        case WEST:
            return texture + "_w";
    }
}
