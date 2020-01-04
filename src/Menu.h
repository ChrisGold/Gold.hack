#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include "TickContext.h"
#include "resources/TileSet.h"
#include "resources/TextureSet.h"

class Menu {
public:
    void draw(sf::RenderTarget &target, TileSet &tileset, TextureSet &textureset);

    void tick(TickContext &ctx);

    void click(int x, int y);
};
