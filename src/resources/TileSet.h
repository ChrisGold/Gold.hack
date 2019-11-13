#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics/Sprite.hpp>

#include "Tile.h"

class TileSet
{
    std::vector<std::shared_ptr<Tile>> tiles;
    void load(std::string& file);
public:
    std::shared_ptr<const Tile> getById(int id);
    void load(std::vector<std::string> &files);
    sf::Sprite make_sprite(int id);
    static TileSet init();
};
