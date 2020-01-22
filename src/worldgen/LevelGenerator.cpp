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

void LevelGenerator::npc(NPCSpec spec) {
    Actor *npc = new Character(spec.name, 1, spec.pos);
    npcs.push_back(npc);
}

Level LevelGenerator::export_level() {
    auto l = Level(level, entryPosition, exitPosition);
    l.npcs = npcs;
    return l;
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

void LevelGenerator::reset() {
    *this = LevelGenerator();
}

void LevelGenerator::calculate_outer_walls() {
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
    for (auto npcSpec : levelSpec.npcs) {
        npc(npcSpec);
    }
    entryPosition = levelSpec.entry;
    exitPosition = levelSpec.exit;
    calculate_outer_walls();
}

bool in_level(int x, int y) {
    return x >= 0 && x < LEVEL_X_SIZE && y >= 0 && y < LEVEL_Y_SIZE;
}
