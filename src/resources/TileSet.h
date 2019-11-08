#pragma once

#include <memory>
#include <string>
#include "Tile.h"

class TileSet
{
    std::vector<std::shared_ptr<Tile>> tiles;
    void load(std::string& file);
public:
    const std::shared_ptr<Tile> getById(int id);
    void load(std::vector<std::string> &files);
    static TileSet init();
};
