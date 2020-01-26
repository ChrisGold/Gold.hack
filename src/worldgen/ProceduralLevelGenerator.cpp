//
// Created by christian on 23.01.20.
//

#include <random>
#include "../Direction.h"
#include "ProceduralLevelGenerator.h"

void ProceduralLevelGenerator::generate() {
    entryPosition = sf::Vector2i(0, 0);
    exitPosition = sf::Vector2i(LEVEL_X_SIZE - 1, LEVEL_Y_SIZE - 1);
    currentWall = "stone_w";
    currentFloor = "stone_f";
    dfsGenerate();
    debugOutput(entryPosition.x, entryPosition.y);
}

void ProceduralLevelGenerator::dfsGenerate() {
    std::vector<sf::Vector2i> visited;
    dfsGenerate(entryPosition, visited);
}

void ProceduralLevelGenerator::dfsGenerate(sf::Vector2i cell, std::vector<sf::Vector2i> &visited) {
    visited.push_back(cell);
    for (auto neighborDirection : neighborsRandomOrder(cell)) {
        auto neighborPos = cell + toVector(neighborDirection);
        if (std::find(visited.begin(), visited.end(), neighborPos) == visited.end()) {
            auto &tile = level[cell.x][cell.y];
            auto &neighbor = level[neighborPos.x][neighborPos.y];
            tile.wall_tile = currentWall;
            tile.floor_tile = currentFloor;
            switch (neighborDirection) {
                case NORTH:
                    tile.pass_north = true;
                    neighbor.pass_south = true;
                    break;
                case SOUTH:
                    tile.pass_south = true;
                    neighbor.pass_north = true;
                    break;
                case EAST:
                    tile.pass_east = true;
                    neighbor.pass_west = true;
                    break;
                case WEST:
                    tile.pass_west = true;
                    neighbor.pass_east = true;
                    break;
                case SELF:
                    break;
            }
            dfsGenerate(neighborPos, visited);
        }
    }
}

void ProceduralLevelGenerator::debugOutput(int x, int y) {
    for (int i = 0; i < LEVEL_Y_SIZE; i++) {
        for (int j = 0; j < LEVEL_X_SIZE; j++) {
            if (level[j][i].pass_north) {
                std::cout << "+   ";
            } else {
                std::cout << "+---";
            }
        }
        std::cout << "+" << std::endl;
        for (int j = 0; j < LEVEL_X_SIZE; j++) {
            if (level[j][i].pass_west) {
                std::cout << " ";
            } else {
                std::cout << "|";
            }
            if (x == j && y == i) {
                std::cout << " X ";
            } else {
                std::cout << "   ";
            }
        }
        std::cout << "|" << std::endl;
    }
    for (int j = 0; j < LEVEL_X_SIZE; j++) {
        std::cout << "+---";
    }
    std::cout << "+" << std::endl;
}

std::vector<Direction> neighborsRandomOrder(sf::Vector2i cell) {
    std::vector<Direction> directions = {Direction::NORTH, Direction::SOUTH, Direction::EAST, Direction::WEST};
    std::shuffle(directions.begin(), directions.end(), std::random_device());
    auto neighbors = std::vector<Direction>();
    neighbors.reserve(4);
    for (Direction d : directions) {
        auto neighbor = cell + toVector(d);
        if (neighbor.x >= 0 && neighbor.x < LEVEL_X_SIZE && neighbor.y >= 0 && neighbor.y < LEVEL_Y_SIZE) {
            neighbors.push_back(d);
        }
    }
    return neighbors;
}

void ProceduralLevelGenerator::plotRoom(int x, int y, int width, int height) {
    room(sf::IntRect(x, y, width, height), currentFloor, currentWall);
}
