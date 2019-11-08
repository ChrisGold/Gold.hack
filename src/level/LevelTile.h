#pragma once

#include <memory>
#include "../resources/Tile.h"

struct LevelTile {
    bool pass_north = true;
    bool pass_east = true;
    int tile_id = 0;
};

