#pragma once

#include <memory>
#include "../Constants.h"

struct LevelTile {
    bool pass_north = false;
    bool pass_east = false;
    bool pass_south = false;
    bool pass_west = false;
    std::string floor_tile = VOID_NAME;
    std::string wall_tile = VOID_NAME;
};

