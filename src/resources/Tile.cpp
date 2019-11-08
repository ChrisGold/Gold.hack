#include "Tile.h"

Tile::Tile(sf::Texture texture, sf::Sprite sprite, std::string name, int id)
{
    this->texture = texture;
    this->sprite = sprite;
    this->name = name;
    this->id = id;
}