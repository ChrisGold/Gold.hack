#pragma once

#include <queue>
#include "Action.h"
#include "../Direction.h"

class Level;
class Actor {

    Level *level;
    std::queue<Action *> actions;
public:
    Actor(Level *level, int textureId, const sf::Vector2i &position);

    Actor(Level *level, std::string name, int textureId, const sf::Vector2i &position);

    sf::Vector2i position;
    Direction facing;
    const std::string name;

    int texture_id;

    void enqueue(Action *action);

    bool act();

};