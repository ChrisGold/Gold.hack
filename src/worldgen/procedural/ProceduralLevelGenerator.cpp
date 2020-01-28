//
// Created by christian on 23.01.20.
//

#include <random>
#include "../../Direction.h"
#include "ProceduralLevelGenerator.h"

void ProceduralLevelGenerator::generate(const ProceduralLevelSpec &spec) {
    currentWall = VOID_NAME;
    currentFloor = spec.floor;
    dfsGenerate();
    std::random_device r;

    for (const auto &roomSpec: spec.rooms) {
        createRoom(r, roomSpec);
    }

    calculate_outer_walls();

    std::vector<sf::Vector2i> positions = freePositions();
    std::shuffle(positions.begin(), positions.end(), r);

    entryPosition = positions.back();
    positions.pop_back();
    exitPosition = positions.back();
    positions.pop_back();

    for (const auto &npcSpec: spec.npcs) {
        for (int i = 0; i < npcSpec.count; i++) {
            NPCSpec singleSpec(npcSpec.name, npcSpec.type, npcSpec.maxHealth, positions.back());
            positions.pop_back();
            npc(singleSpec);
        }
    }
    level[exitPosition.x][exitPosition.y].floor_tile = spec.exit_tile;
}

void ProceduralLevelGenerator::expandMaze() {
    for (int m_x = 0; m_x < MAZE_X_SIZE; m_x++) {
        for (int m_y = 0; m_y < MAZE_Y_SIZE; m_y++) {
            auto &tile = maze[m_x][m_y];
            level[m_x * 2][m_y * 2] = tile;
            if (tile.pass_south) {
                auto &south = level[m_x * 2][m_y * 2 + 1];
                south = tile;
                south.pass_north = true;
                south.pass_south = true;
                south.pass_east = false;
                south.pass_west = false;

            }
            if (tile.pass_east) {
                auto &east = level[m_x * 2 + 1][m_y * 2];
                east = tile;
                east.pass_north = false;
                east.pass_south = false;
                east.pass_west = true;
                east.pass_east = true;
            }
        }
    }
}

void ProceduralLevelGenerator::dfsGenerate() {
    std::vector<sf::Vector2i> visited;
    dfsGenerate(entryPosition, visited);
    expandMaze();
}

void ProceduralLevelGenerator::dfsGenerate(sf::Vector2i cell, std::vector<sf::Vector2i> &visited) {
    visited.push_back(cell);
    for (auto neighborDirection : neighborsRandomOrder(cell, MAZE_X_SIZE, MAZE_Y_SIZE)) {
        auto neighborPos = cell + toVector(neighborDirection);
        if (std::find(visited.begin(), visited.end(), neighborPos) == visited.end()) {
            auto &tile = maze[cell.x][cell.y];
            auto &neighbor = maze[neighborPos.x][neighborPos.y];
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

typedef std::uniform_int_distribution<int> dice;

void ProceduralLevelGenerator::createRoom(std::random_device &rand, const ProceduralRoomSpec &roomSpec) {
    auto xCorner = dice(0, LEVEL_X_SIZE - roomSpec.size.x);
    auto yCorner = dice(0, LEVEL_Y_SIZE - roomSpec.size.y);

    auto bounds = sf::IntRect(xCorner(rand), yCorner(rand), roomSpec.size.x, roomSpec.size.y);
    std::cout << "Generating room: x=" << bounds.left << ", y=" << bounds.top << ", w=" << bounds.width << ", h"
              << bounds.height << std::endl;
    room(bounds, roomSpec.floor, VOID_NAME);
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

std::vector<Direction> neighborsRandomOrder(sf::Vector2i cell, int x_max, int y_max) {
    std::vector<Direction> directions = {Direction::NORTH, Direction::SOUTH, Direction::EAST, Direction::WEST};
    std::shuffle(directions.begin(), directions.end(), std::random_device());
    auto neighbors = std::vector<Direction>();
    neighbors.reserve(4);
    for (Direction d : directions) {
        auto neighbor = cell + toVector(d);
        if (neighbor.x >= 0 && neighbor.x < x_max && neighbor.y >= 0 && neighbor.y < y_max) {
            neighbors.push_back(d);
        }
    }
    return neighbors;
}

void ProceduralLevelGenerator::plotRoom(int x, int y, int width, int height) {
    room(sf::IntRect(x, y, width, height), currentFloor, currentWall);
}

ProceduralLevelGenerator::ProceduralLevelGenerator() : LevelGenerator() {
    for (int x = 0; x < MAZE_X_SIZE; x++) {
        for (int y = 0; y < MAZE_Y_SIZE; y++) {
            auto &tile = maze[x][y];
        }
    }
}

std::vector<sf::Vector2i> ProceduralLevelGenerator::freePositions() {
    std::vector<sf::Vector2i> pos;
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            if (level[x][y].floor_tile != VOID_NAME) {
                pos.emplace_back(x, y);
            }
        }
    }
    return pos;

}