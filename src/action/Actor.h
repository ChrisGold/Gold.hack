#pragma once

#include <queue>
#include "../level/Level.h"
#include "../Game.h"
#include "Action.h"

class Actor {
    Game &game;
    Level &level;
    std::queue<std::shared_ptr<const Action>> actions;

    int texture_id;
public:
    Actor(Game &game, Level &level, int textureId,
          const sf::Vector2i &position);

private:
    sf::Vector2i position;

    void act();

    void enqueue(std::shared_ptr<const Action> action);
};