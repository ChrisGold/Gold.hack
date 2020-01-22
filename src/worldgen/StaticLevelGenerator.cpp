//
// Created by christian on 23.01.20.
//

#include "StaticLevelGenerator.h"

void StaticLevelGenerator::generate(LevelSpec &levelSpec, Config &config) {
    for (auto roomSpec : levelSpec.rooms) {
        room(sf::IntRect(roomSpec.position, roomSpec.size), roomSpec.floor, roomSpec.wall);
    }
    for (auto npcSpec : levelSpec.npcs) {
        npc(npcSpec);
    }
    entryPosition = levelSpec.entry;
    exitPosition = levelSpec.exit;
    calculate_outer_walls();
}