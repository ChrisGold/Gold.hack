#include "Actor.h"

void Actor::act() {
    if (!actions.empty()) {
        auto action = actions.back();
    }
}

void Actor::enqueue(const std::shared_ptr<const Action> action) {
    actions.push(action);
}

Actor::Actor(Game &game, Level &level, int textureId, const sf::Vector2i &position) :
        game(game), level(level), actions(), texture_id(textureId), position(position) {}
