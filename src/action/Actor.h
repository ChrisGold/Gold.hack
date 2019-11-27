#pragma once

#include <queue>
#include "../level/Level.h"
#include "../Game.h"
#include "Action.h"
#include "../Types.h"

class Actor {
    GamePtr game;
    Level &level;
    std::queue<std::shared_ptr<Action>> actions;
    int texture_id;
public:

    Actor(GamePtr game, Level &level, int textureId,
          const sf::Vector2i &position);
    sf::Vector2i position;

private:
    void act();

    void enqueue(const std::shared_ptr<Action> &action);
};