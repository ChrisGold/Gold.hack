#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Tile {
    sf::Texture texture;
    sf::Sprite sprite;
    std::string name;
    int id;
};