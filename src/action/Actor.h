#pragma once

#include <queue>
#include <SFML/Graphics/Rect.hpp>
#include "Action.h"
#include "../Direction.h"
#include "../TickContext.h"

class Actor {

    std::queue<Action *> actions;
    int max_health;
    int health;

public:
    Actor(int textureId, const sf::Vector2i &position, int max_health);

    Actor(std::string name, int textureId, const sf::Vector2i &position, int max_health);

    sf::Vector2i position;
    Direction facing;
    const std::string name;

    int texture_id;


    const std::string &getName() const;

    int getMaxHealth() const;

    int getHealth() const;

    bool isAlive() const;

    int takeDamage(int hp);

    void enqueue(Action *action);

    virtual bool act(TickContext &ctx);

    sf::Rect<float> getRect();
};