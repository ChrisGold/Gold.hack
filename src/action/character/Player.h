#pragma once

#include "../Actor.h"

class Player : public Actor {
public:
    Player(const std::string &name, int textureId, const sf::Vector2i &position);
};
