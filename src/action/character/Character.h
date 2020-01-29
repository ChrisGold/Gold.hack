#include "../Actor.h"
#pragma once

class Character : public Actor {
    static int counter;
public:
    Character(const std::string &name, std::string texture, const sf::Vector2i &position);
};
