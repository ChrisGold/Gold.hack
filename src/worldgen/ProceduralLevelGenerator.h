#pragma once

#include "LevelGenerator.h"

class ProceduralLevelGenerator : public LevelGenerator {
    std::string currentWall;
    std::string currentFloor;
public:
    void generate();

    void plotRoom(int x, int y, int width, int height);

    void dfsGenerate(sf::Vector2i cell, std::vector<sf::Vector2i> &visited);

    void dfsGenerate();

    void debugOutput(int x, int y);
};

std::vector<Direction> neighborsRandomOrder(sf::Vector2i cell);
