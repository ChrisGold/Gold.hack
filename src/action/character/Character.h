#include "../Actor.h"

class Character : public Actor {
    static int counter;
public:
    Character(const std::string &name, int textureId, const sf::Vector2i &position);

    bool act(const TickContext &ctx) override;
};
