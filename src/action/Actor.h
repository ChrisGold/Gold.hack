#pragma once

#include <queue>
#include <SFML/Graphics/Rect.hpp>
#include "Action.h"
#include "../Direction.h"
#include "../TickContext.h"

class Actor {

    std::queue<Action *> actions;
public:
    Actor(int textureId, const sf::Vector2i &position);

    Actor(std::string name, int textureId, const sf::Vector2i &position);

    sf::Vector2i position;
    Direction facing;
    const std::string name;

    int texture_id;

    void enqueue(Action *action);

    virtual bool act(const TickContext &ctx);

    sf::Rect<float> getRect();
};