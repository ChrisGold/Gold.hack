#include "LevelGenerator.h"
#include "../action/character/Character.h"
#include "../action/character/Fighter.h"

void LevelGenerator::room(sf::IntRect rect, const std::string &floor_material, const std::string &wall_material) {
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
    Actor *npc;
    if (spec.type == "fighter") {
        npc = new Fighter(spec.name, 1, spec.pos);
    } else {
        npc = new Character(spec.name, 1, spec.pos);
    }
    npcs.push_back(npc);
}

Level LevelGenerator::export_level() {
    auto l = Level(level, entryPosition, exitPosition);
    l.npcs = npcs;
    l.debugOutput();
    return l;
}

LevelGenerator::LevelGenerator() {
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            LevelTile &t = level[x][y];
            t.pass_north = false;
            t.pass_south = false;
            t.pass_east = false;
            t.pass_west = false;
            t.floor_tile = VOID_NAME;
            t.wall_tile = VOID_NAME;
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
                t.pass_east = east.floor_tile != VOID_NAME;
            } else t.pass_east = false;
            //North
            if (in_level(x, y - 1)) {
                LevelTile &north = level[x][y - 1];
                t.pass_north = north.floor_tile != VOID_NAME;
            } else t.pass_north = false;
            //West
            if (in_level(x - 1, y)) {
                LevelTile &west = level[x - 1][y];
                t.pass_west = west.floor_tile != VOID_NAME;
            } else t.pass_west = false;
            //South
            if (in_level(x, y + 1)) {
                LevelTile &south = level[x][y + 1];
                t.pass_south = south.floor_tile != VOID_NAME;
            } else t.pass_south = false;
        }
    }
}

bool in_level(int x, int y) {
    return x >= 0 && x < LEVEL_X_SIZE && y >= 0 && y < LEVEL_Y_SIZE;
}
