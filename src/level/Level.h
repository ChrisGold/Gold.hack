#pragma once
#include <SFML/Graphics/RenderTarget.hpp>
#include <vector>

#include "LevelTile.h"
#include "../Constants.h"

class Level {
    LevelTile tiles[LEVEL_X_SIZE][LEVEL_Y_SIZE];
public:
    Level();
    void draw(sf::RenderTarget& target);
    static std::vector<Level> make();
};
