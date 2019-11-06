#pragma once

#include "LevelTile.h"

template<int X_SIZE, int Y_SIZE>
class Level {
    Tile tiles[X_SIZE][Y_SIZE];
public:
    Level() = default;
};
