#include "../Actor.h"
#pragma once

class Character : public Actor {
    static int counter;
public:
    Character(const std::string &name, int textureId, const sf::Vector2i &position);
};
