#pragma once

#include <memory>
#include "../Constants.h"
#include "../level/LevelTile.h"
#include "../level/Level.h"

class LevelGenerator {
    void room(sf::IntRect rect, int floor_material, int wall_material);

public:
    LevelGenerator();

    LevelTile level[LEVEL_X_SIZE][LEVEL_Y_SIZE];

    void generate();

    Level export_level();
};