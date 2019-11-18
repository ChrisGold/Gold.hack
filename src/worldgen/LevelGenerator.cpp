#include "LevelGenerator.h"

void LevelGenerator::room(sf::IntRect rect, int floor_material, int wall_material) {
    for (int x = 0; x < rect.width; ++x) {
        for (int y = 0; y < rect.height; ++y) {
            LevelTile &t = this->level[rect.left + x][rect.top + y];
            t.pass_north = y != 0;
            t.pass_east = x != rect.width - 1;
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
            LevelTile &t = level[x][y];
            t.pass_east = false;
            t.pass_north = false;
            t.floor_tile = 0;
            t.wall_tile = 0;
        }
    }
}
