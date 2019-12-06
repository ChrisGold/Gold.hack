#include <utility>

#include "Actor.h"

bool Actor::act() {
    if (!actions.empty()) {
        auto action = actions.front();
        action->execute(this);
        actions.pop();
        return true;
    } else return false;
}

void Actor::enqueue(const std::shared_ptr<Action> &action) {
    actions.push(action);
}

Actor::Actor(GamePtr game, LevelPtr level, int textureId, const sf::Vector2i &position) :
        game(std::move(game)),
        level(std::move(level)),
        actions(),
        facing(Direction::SOUTH),
        texture_id(textureId),
        position(position) {
}
