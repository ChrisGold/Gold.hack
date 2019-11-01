#ifndef GOLD_HACK_LEVEL_H
#define GOLD_HACK_LEVEL_H


#include "Tile.h"

template<int X_SIZE, int Y_SIZE>
class Level {
    Tile tiles[X_SIZE][Y_SIZE];
public:
    Level() = default;
};



#endif //GOLD_HACK_LEVEL_H
