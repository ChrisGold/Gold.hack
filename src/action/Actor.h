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

protected:
    std::string texture;
public:

    Actor(std::string name, std::string texture, const sf::Vector2i &position, int max_health);

    sf::Vector2i position;
    Direction facing;

    const std::string name;

    virtual std::string getTexture() const;

    const std::string &getName() const;

    int getMaxHealth() const;

    int getHealth() const;

    bool isAlive() const;

    int takeDamage(int hp);

    void enqueue(Action *action);

    virtual bool act(TickContext &ctx);

    sf::Rect<float> getRect();
};