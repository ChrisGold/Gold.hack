#pragma once

#include <memory>
#include "../Constants.h"
#include "../level/LevelTile.h"
#include "../level/Level.h"
#include "LevelSpec.h"
#include "../resources/Config.h"

class LevelGenerator {
protected:
    void room(sf::IntRect rect, const std::string &floor_material, const std::string &wall_material);

    void calculate_outer_walls();

public:
    LevelGenerator();

    LevelTile level[LEVEL_X_SIZE][LEVEL_Y_SIZE];
    std::vector<Actor *> npcs;
    sf::Vector2i entryPosition;
    sf::Vector2i exitPosition;

    Level export_level();

    void reset();

    void npc(NPCSpec spec);
};

bool in_level(int x, int y);