#pragma once

#include <SFML/Graphics/Texture.hpp>

struct Tile {
    sf::Texture floor;
    sf::Texture wall;
    std::string name;
    int id;

    Tile(sf::Texture floor, sf::Texture wall, std::string name, int id);
};