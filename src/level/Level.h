#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <vector>

#include "LevelTile.h"
#include "../resources/TileSet.h"
#include "../Constants.h"
#include "../resources/TextureSet.h"
#include "../action/Actor.h"
#include "../TickContext.h"

class Level {
public:
    Level();

    explicit Level(LevelTile[LEVEL_X_SIZE][LEVEL_Y_SIZE]);

    Actor *player;
    std::vector<Actor *> npcs;

    void draw(sf::RenderTarget &target, TileSet &tileset, TextureSet &textureset);

    bool tick(const TickContext &ctx);

    void enqueue(Action *action);

    LevelTile tiles[LEVEL_X_SIZE][LEVEL_Y_SIZE];

    static std::vector<Level> make();
};
