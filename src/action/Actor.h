#pragma once

#include <queue>
#include "../level/Level.h"
#include "../Game.h"
#include "Action.h"

class Actor {
    Game &game;
    Level &level;
    std::queue<std::shared_ptr<Action>> actions;
    int texture_id;
public:

    Actor(Game &game, Level &level, int textureId,
          const sf::Vector2i &position);
    sf::Vector2i position;

private:
    void act();

    void enqueue(const std::shared_ptr<Action> &action);
};