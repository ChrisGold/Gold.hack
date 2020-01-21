#include <utility>

#include "Actor.h"
#include "../Constants.h"
#include <SFML/Graphics/Rect.hpp>

bool Actor::act(TickContext &ctx) {
    if (actions.empty()) return false;
    else {
        auto action = actions.front();
        action->execute(ctx, this);
        actions.pop();
        delete action;
        return true;
    }
}

void Actor::enqueue(Action *action) {
    actions.push(action);
}

int actor_counter = 0;

Actor::Actor(std::string name, int textureId, const sf::Vector2i &position, int max_health = 0) :
        actions(),
        name(std::move(name)),
        facing(Direction::SOUTH),
        texture_id(textureId),
        position(position),
        max_health(max_health),
        health(max_health) {
}

Actor::Actor(int textureId, const sf::Vector2i &position, int max_health = 0) :
        actions(),
        name("MOB " + std::to_string(actor_counter++)),
        facing(Direction::SOUTH),
        texture_id(textureId),
        position(position),
        max_health(max_health),
        health(max_health) {
}

sf::FloatRect Actor::getRect() {
    return sf::FloatRect(position.x * TILE_X_SIZE, position.y * TILE_Y_SIZE, TILE_X_SIZE,
                         TILE_Y_SIZE);
}

bool Actor::isAlive() const {
    return max_health == 0 || health > 0;
}

int Actor::takeDamage(int hp) {
    if (max_health == 0) {
        return 0;
    }
    health = health - hp;
    health = std::clamp(health, 0, max_health);
    return health;
}

const std::string &Actor::getName() const {
    return name;
}

int Actor::getMaxHealth() const {
    return max_health;
}

int Actor::getHealth() const {
    return health;
}
