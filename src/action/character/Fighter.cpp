//
// Created by christian on 23.01.20.
//

#include <cmath>
#include "Fighter.h"
#include "../../level/Level.h"
#include "../Attack.h"
#include "../Walk.h"

bool Fighter::act(TickContext &ctx) {
    if (!tryAttack(ctx)) {
        tryAdvance(ctx);
    }
    return true;
}

bool Fighter::tryAttack(TickContext &ctx) {
    for (Direction d : ALL_DIRECTIONS) {
        auto target = ctx.level->at(position + toVector(d));
        if (target != nullptr && (dynamic_cast<Player *>(target))) {
            facing = d;
            Attack a = Attack();
            a.execute(ctx, this);
            break;
        }
    }
}

bool Fighter::tryAdvance(TickContext &ctx) {
    auto distanceVector = (ctx.level->player->position - position);
    auto distanceToPlayer = float(sqrt(distanceVector.x * distanceVector.x + distanceVector.y * distanceVector.y));
    if (distanceToPlayer < 5) {
        auto d = advanceDirection(sf::Vector2f(distanceVector.x, distanceVector.y));
        Walk(d).execute(ctx, this);
    }
}

float norm(sf::Vector2f vec) {
    return float(sqrt(vec.x * vec.x + vec.y * vec.y));
}


Direction advanceDirection(sf::Vector2f exact) {
    exact = exact / norm(exact);
    auto directionVectors = std::vector<sf::Vector2i>(ALL_DIRECTIONS.size());
    std::transform(ALL_DIRECTIONS.begin(), ALL_DIRECTIONS.end(), directionVectors.begin(),
                   [](Direction d) { return toVector(d); });
    auto errors = std::vector<float>(4);
    std::transform(directionVectors.begin(), directionVectors.end(), errors.begin(), [exact](sf::Vector2i vec) {
        auto xError = exact.x - vec.x;
        auto yError = exact.y - vec.y;
        return norm(sf::Vector2f(xError, yError));
    });
    auto bestDirection = std::min_element(errors.begin(), errors.end()) - errors.begin();
    return ALL_DIRECTIONS[bestDirection];
}

Fighter::Fighter(const std::string &name, int textureId, const sf::Vector2i &position) : Character(name, textureId,
                                                                                                   position) {}
