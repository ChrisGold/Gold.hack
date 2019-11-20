#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <vector>

#include "LevelTile.h"
#include "../resources/TileSet.h"
#include "../Constants.h"
#include "../resources/TextureSet.h"

class Level {
    LevelTile tiles[LEVEL_X_SIZE][LEVEL_Y_SIZE];
    sf::Vector2i playerPos;
public:
    Level();

    Level(LevelTile[LEVEL_X_SIZE][LEVEL_Y_SIZE]);

    void draw(sf::RenderTarget &target, TileSet &tileset, TextureSet &textureset);

    static std::vector<Level> make();
};
