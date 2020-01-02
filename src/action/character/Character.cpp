//
// Created by christian on 02.01.20.
//

#include "Character.h"
#include "../Walk.h"

Character::Character(const std::string &name, int textureId, const sf::Vector2i &position) : Actor(name, textureId,
                                                                                                   position) {
}

int Character::counter = 0;