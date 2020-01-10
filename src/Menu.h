#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include "TickContext.h"
#include "resources/Resources.h"
#include "GameStage.h"

class Menu {
    GameStage next = MENU;
public:
    void draw(sf::RenderTarget &target, Resources &resources);

    void reset();

    void tick(TickContext &ctx);

    void click(int x, int y);
};
