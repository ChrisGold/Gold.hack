#pragma once

#include "LevelGenerator.h"

class StaticLevelGenerator : public LevelGenerator {
public:
    void generate(LevelSpec &levelSpec, Config &config);
};
