#pragma once

#include <memory>
#include "../resources/Tile.h"

struct LevelTile {
    bool pass_north = true;
    bool pass_east = true;
    std::shared_ptr<Tile> tile = nullptr;
};

