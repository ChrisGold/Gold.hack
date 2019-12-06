#pragma once

#include <queue>
#include "../level/Level.h"
#include "../Game.h"
#include "Action.h"
#include "../Types.h"

class Actor {
    GamePtr game;
    LevelPtr level;
    std::queue<std::shared_ptr<Action>> actions;
public:

    Actor(GamePtr game, LevelPtr level, int textureId,
          const sf::Vector2i &position);
    sf::Vector2i position;
    Direction facing;

    int texture_id;

    void enqueue(const std::shared_ptr<Action> &action);

    bool act();

};