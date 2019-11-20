#include "LevelGenerator.h"
#include <iostream>

void LevelGenerator::room(sf::IntRect rect, int floor_material, int wall_material) {
    for (int x = 0; x < rect.width; ++x) {
        for (int y = 0; y < rect.height; ++y) {
            if (in_level(rect.left + x, rect.top + y)) {
                LevelTile &t = this->level[rect.left + x][rect.top + y];
                t.pass_north = y != 0;
                t.pass_east = x != rect.width - 1;
                t.floor_tile = floor_material;
                t.wall_tile = wall_material;
            }
        }
    }
    for (int x = 0; x < rect.width; ++x) {
        if (in_level(rect.left + x, rect.top + rect.height)) {
            LevelTile &bottom = this->level[rect.left + x][rect.top + rect.height];
            bottom.pass_north = false;
            bottom.wall_tile = wall_material;
        }
    }
    for (int y = 0; y < rect.height; ++y) {
        if (in_level(rect.left - 1, rect.top + y)) {
            LevelTile &bottom = this->level[rect.left - 1][rect.top + y];
            bottom.pass_east = false;
            bottom.wall_tile = wall_material;
        }
    }
}

Level LevelGenerator::export_level() {
    return Level(level);
}

void LevelGenerator::generate() {
    room(sf::IntRect(1, 1, 5, 5), 2, 1);
    room(sf::IntRect(7, 1, 5, 5), 1, 2);
}

LevelGenerator::LevelGenerator() {
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            LevelTile &t = level[x][y];
            t.pass_east = true;
            t.pass_north = true;
            t.floor_tile = 0;
            t.wall_tile = 0;
        }
    }
}

bool in_level(int x, int y) {
    return x >= 0 && x < LEVEL_X_SIZE && y >= 0 && y < LEVEL_Y_SIZE;
}
