#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include "TickContext.h"
#include "resources/Resources.h"

class Menu {
public:
    void draw(sf::RenderTarget &target, Resources &resources);

    void tick(TickContext &ctx);

    void click(int x, int y);
};
