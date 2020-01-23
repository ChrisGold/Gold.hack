#pragma once

#include "LevelGenerator.h"

class ProceduralLevelGenerator : public LevelGenerator {
    std::string currentWall;
    std::string currentFloor;
public:
    void generate();

    void plotRoom(int x, int y, int width, int height);
};
