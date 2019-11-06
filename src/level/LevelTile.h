#pragma once
#include "../resources/Tile.h"

struct LevelTile {
    bool pass_north = true;
    bool pass_east = true;
    Tile * tile = nullptr;
};

