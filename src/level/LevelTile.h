#pragma once

#include <memory>
#include "../Constants.h"

struct LevelTile {
    bool pass_north = true;
    bool pass_east = true;
    bool pass_south = true;
    bool pass_west = true;
    std::string floor_tile = VOID_NAME;
    std::string wall_tile = VOID_NAME;
};

