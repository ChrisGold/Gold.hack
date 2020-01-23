//
// Created by christian on 23.01.20.
//

#include "ProceduralLevelGenerator.h"

void ProceduralLevelGenerator::generate() {
    entryPosition = sf::Vector2i(0, 0);
    exitPosition = sf::Vector2i(LEVEL_X_SIZE - 1, LEVEL_Y_SIZE - 1);
    currentWall = "stone_w";
    currentFloor = "stone_f";
    plotRoom(0, 0, LEVEL_X_SIZE, LEVEL_Y_SIZE);
    calculate_outer_walls();
}

void ProceduralLevelGenerator::plotRoom(int x, int y, int width, int height) {
    room(sf::IntRect(x, y, width, height), currentFloor, currentWall);
}
