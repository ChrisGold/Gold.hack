#include "LevelGenerator.h"

void LevelGenerator::room(sf::IntRect rect, int floor_material, int wall_material) {
    for (int x = rect.left; x < rect.left + rect.width; ++x) {
        for (int y = rect.top; x < rect.top + rect.height; ++y) {
            LevelTile &t = this->level[x][y];
            t.pass_north = y == rect.top;
            t.pass_east = x == rect.top + rect.height - 1;
            t.floor_tile = floor_material;
            t.wall_tile = wall_material;
        }
    }
}

Level LevelGenerator::export_level() {
    return Level(level);
}

void LevelGenerator::generate() {
    room(sf::IntRect(1, 1, 5, 5), 2, 1);
}

LevelGenerator::LevelGenerator() {
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            LevelTile t = level[x][y];
            t.pass_east = false;
            t.pass_north = false;
            t.floor_tile = 0;
            t.wall_tile = 0;
        }
    }
}
