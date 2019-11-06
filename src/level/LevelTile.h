#ifndef GOLD_HACK_LEVEL_TILE_H
#define GOLD_HACK_LEVEL_TILE_H
#include "../resources/Tile.h"

struct LevelTile {
    bool pass_north = true;
    bool pass_east = true;
    Tile * tile = nullptr;
};

#endif //GOLD_HACK_TILE_H
