#pragma once

#include <string>
#include "Tile.h"

class TileSet
{
    std::vector<Tile> textures;

public:
    const Tile &getById(int id);
    const Tile &getByName(std::string &name);
};
