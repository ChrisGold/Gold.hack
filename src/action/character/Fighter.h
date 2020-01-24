#pragma once

#include "Character.h"

class Fighter : public Character {
public:
    bool act(TickContext &ctx) override;

    Fighter(const std::string &name, int textureId, const sf::Vector2i &position);
};
