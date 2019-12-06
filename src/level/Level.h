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
public:
    explicit Level(GamePtr);

    Level(GamePtr, LevelTile[LEVEL_X_SIZE][LEVEL_Y_SIZE]);

    Actor *player;

    void draw(sf::RenderTarget &target, TileSet &tileset, TextureSet &textureset);

    bool tick();

    static std::vector<std::shared_ptr<Level>> make(GamePtr gamePtr);

    void enqueue(ActionPtr action);

    LevelTile tiles[LEVEL_X_SIZE][LEVEL_Y_SIZE];
};
