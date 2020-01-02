#include <utility>

#include "Actor.h"
#include "../Constants.h"
#include <SFML/Graphics/Rect.hpp>

bool Actor::act(const TickContext &ctx) {
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

Actor::Actor(std::string name, int textureId, const sf::Vector2i &position) :
        actions(),
        name(std::move(name)),
        facing(Direction::SOUTH),
        texture_id(textureId),
        position(position) {
}

Actor::Actor(int textureId, const sf::Vector2i &position) :
        actions(),
        name("MOB " + std::to_string(actor_counter++)),
        facing(Direction::SOUTH),
        texture_id(textureId),
        position(position) {
}

sf::FloatRect Actor::getRect() {
    return sf::FloatRect(position.x * TILE_X_SIZE, position.y * TILE_Y_SIZE, TILE_X_SIZE,
                         TILE_Y_SIZE);
}