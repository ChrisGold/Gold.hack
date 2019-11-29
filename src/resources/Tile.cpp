#include "Tile.h"

Tile::Tile(sf::Texture floor, std::string name, int id) {
    this->texture = floor;
    this->name = name;
    this->id = id;
}