#pragma once

#include "../Actor.h"

class Player : public Actor {
public:
    Player(const std::string &name, std::string texture, const sf::Vector2i &position);

    std::string getTexture() const override;
};
