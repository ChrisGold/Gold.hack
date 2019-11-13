#pragma once

#include <memory>
#include "../resources/Tile.h"

struct LevelTile {
    bool pass_north = true;
    bool pass_east = true;
    int floor_tile = 0;
    int wall_tile = 0;
};

