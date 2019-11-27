#include <utility>

#include "Actor.h"

void Actor::act() {
    if (!actions.empty()) {
        auto action = actions.back();
        action->execute(this);
    }
}

void Actor::enqueue(const std::shared_ptr<Action> &action) {
    actions.push(action);
}

Actor::Actor(GamePtr game, Level &level, int textureId, const sf::Vector2i &position) :
        game(std::move(game)), level(level), actions(), texture_id(textureId), position(position) {}
