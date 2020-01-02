#include <utility>

#include "Actor.h"

bool Actor::act(const TickContext &ctx) {
    if (!actions.empty()) {
        auto action = actions.front();
        action->execute(ctx, this);
        actions.pop();
        return true;
    } else return false;
}

void Actor::enqueue(Action *action) {
    actions.push(action);
}

int actor_counter = 0;

Actor::Actor(Level *level, std::string name, int textureId, const sf::Vector2i &position) :
        level(level),
        actions(),
        name(std::move(name)),
        facing(Direction::SOUTH),
        texture_id(textureId),
        position(position) {
}

Actor::Actor(Level *level, int textureId, const sf::Vector2i &position) :
        level(level),
        actions(),
        name("MOB " + std::to_string(actor_counter++)),
        facing(Direction::SOUTH),
        texture_id(textureId),
        position(position) {
}
