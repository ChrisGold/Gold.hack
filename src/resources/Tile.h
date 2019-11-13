#pragma once

#include <SFML/Graphics/Texture.hpp>

struct Tile {
    sf::Texture texture;
    std::string name;
    int id;
    Tile(sf::Texture texture, std::string name, int id);
};