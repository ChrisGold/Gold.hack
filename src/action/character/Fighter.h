#pragma once

#include "Character.h"

class Fighter : public Character {
    bool tryAttack(TickContext &ctx);

public:

    bool act(TickContext &ctx) override;

    Fighter(const std::string &name, std::string texture, const sf::Vector2i &position);

    bool tryAdvance(TickContext &ctx);
};

float norm(sf::Vector2f vec);

Direction advanceDirection(sf::Vector2f exact);
