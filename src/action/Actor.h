#pragma once

#include <queue>
#include "../level/Level.h"
#include "../Game.h"
#include "Action.h"
#include "../Types.h"
#include "../Direction.h"

class Actor {
    GamePtr game;

    LevelPtr level;
    std::queue<std::shared_ptr<Action>> actions;
public:
    Actor(GamePtr game, LevelPtr level, int textureId, const sf::Vector2i &position);
    Actor(GamePtr game, LevelPtr level, std::string  name, int textureId,
          const sf::Vector2i &position);

    sf::Vector2i position;
    Direction facing;
    const std::string name;

    int texture_id;

    void enqueue(const std::shared_ptr<Action> &action);

    bool act();

};