#pragma once

#include <memory>
#include "../Constants.h"
#include "../level/LevelTile.h"
#include "../level/Level.h"
#include "LevelSpec.h"
#include "../resources/Config.h"

class LevelGenerator {
    void room(sf::IntRect rect, int floor_material, int wall_material);

    void calculate_walls();

public:
    LevelGenerator();

    LevelTile level[LEVEL_X_SIZE][LEVEL_Y_SIZE];
    sf::Vector2i entryPosition;
    sf::Vector2i exitPosition;

    void generate(int type);

    void generate(LevelSpec &levelSpec, Config &config);

    Level export_level();

    void reset();
};

bool in_level(int x, int y);