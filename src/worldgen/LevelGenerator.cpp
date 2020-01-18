#include "LevelGenerator.h"
#include "../action/character/Character.h"

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
}

Level LevelGenerator::export_level() {
    auto l = Level(level, entryPosition, exitPosition, initContext);
    Actor *npc = new Character("Aurelian", 1, exitPosition);
    l.npcs.push_back(npc);
    return l;
}

void LevelGenerator::generate(int type) {
    if (type == 0) {
        entryPosition = sf::Vector2i(0, 0);
        exitPosition = sf::Vector2i(4, 4);
        room(sf::IntRect(1, 1, 5, 5), 2, 3);
        room(sf::IntRect(7, 1, 5, 5), 2, 3);
        room(sf::IntRect(6, 3, 1, 1), 2, 3);
        room(sf::IntRect(0, 0, 1, 8), 2, 3);
        room(sf::IntRect(4, 4, 1, 1), 2, 3);
    } else if (type == 1) {
        entryPosition = sf::Vector2i(0, 4);
        exitPosition = sf::Vector2i(2, 0);
        room(sf::IntRect(0, 0, 3, 5), 2, 3);
    } else if (type == 2) {
        entryPosition = sf::Vector2i(8, 0);
        exitPosition = sf::Vector2i(13, 13);
        room(sf::IntRect(8, 0, 1, 13), 2, 3);
        room(sf::IntRect(0, 13, 13, 1), 2, 3);
        room(sf::IntRect(13, 13, 1, 1), 2, 3);
    }
    calculate_walls();
}

LevelGenerator::LevelGenerator(InitContext initContext) : initContext(initContext) {
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

void LevelGenerator::reset() {
    *this = LevelGenerator(initContext);
}

void LevelGenerator::calculate_walls() {
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            LevelTile &t = level[x][y];
            //East
            if (in_level(x + 1, y)) {
                LevelTile &east = level[x + 1][y];
                t.pass_east = east.floor_tile != 0;
            } else t.pass_east = false;
            //North
            if (in_level(x, y - 1)) {
                LevelTile &north = level[x][y - 1];
                t.pass_north = north.floor_tile != 0;
            } else t.pass_north = false;
            //West
            if (in_level(x - 1, y)) {
                LevelTile &west = level[x - 1][y];
                t.pass_west = west.floor_tile != 0;
            } else t.pass_west = false;
            //South
            if (in_level(x, y + 1)) {
                LevelTile &south = level[x][y + 1];
                t.pass_south = south.floor_tile != 0;
            } else t.pass_south = false;
        }
    }
}

void LevelGenerator::generate(LevelSpec &levelSpec, Config &config) {
    for (auto roomSpec : levelSpec.rooms) {
        int wallId = config.getTextureId(roomSpec.wall);
        int floorId = config.getTextureId(roomSpec.floor);
        room(sf::IntRect(roomSpec.position, roomSpec.size), floorId, wallId);
    }
    entryPosition = levelSpec.entry;
    exitPosition = levelSpec.exit;
    calculate_walls();
}

bool in_level(int x, int y) {
    return x >= 0 && x < LEVEL_X_SIZE && y >= 0 && y < LEVEL_Y_SIZE;
}
