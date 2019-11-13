#include "Tile.h"

Tile::Tile(sf::Texture floor, sf::Texture wall, std::string name, int id) {
    this->floor = floor;
    this->wall = wall;
    this->name = name;
    this->id = id;
}