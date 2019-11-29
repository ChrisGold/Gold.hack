#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <vector>

#include "../Types.h"
#include "LevelTile.h"
#include "../resources/TileSet.h"
#include "../Constants.h"
#include "../resources/TextureSet.h"
#include "../action/Actor.h"

class Level {
    GamePtr game;
    LevelTile tiles[LEVEL_X_SIZE][LEVEL_Y_SIZE];
public:
    explicit Level(GamePtr);

    Level(GamePtr, LevelTile[LEVEL_X_SIZE][LEVEL_Y_SIZE]);

    void draw(sf::RenderTarget &target, TileSet &tileset, TextureSet &textureset);

    Actor *player;

    static std::vector<Level> make(GamePtr gamePtr);
};
