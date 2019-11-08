#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

struct Tile {
    sf::Texture texture;
    sf::Sprite sprite;
    std::string name;
    int id;
    public:
    Tile(sf::Texture texture, sf::Sprite sprite, std::string name, int id);
};