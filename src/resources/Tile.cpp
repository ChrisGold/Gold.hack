#include "Tile.h"

Tile::Tile(sf::Texture texture, std::string name, int id)
{
    this->texture = texture;
    this->name = name;
    this->id = id;
}