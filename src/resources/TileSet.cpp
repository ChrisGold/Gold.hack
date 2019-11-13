#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>
#include "TileSet.h"
#include "../Constants.h"

std::shared_ptr<const Tile> TileSet::getById(int id) {
    return tiles[id];
}

void TileSet::load(std::string &file) {
    //Floor
    std::string path = file + ".png";
    std::cout << "Loading: " << path << std::endl;
    sf::Texture tex;
    tex.loadFromFile(path);

    //Wall
    path = file + ".wall.png";
    sf::Texture wall;
    wall.loadFromFile(path);
    int id = tiles.size();
    auto ptr = std::make_shared<Tile>(tex, wall, file, id);
    tiles.push_back(ptr);
}

void TileSet::load(std::vector<std::string> &files) {
    for (std::string &file : files) load(file);
}

TileSet TileSet::init() {
    TileSet ts{};
    std::vector<std::string> names = {"void", "wood", "stone", "halo"};
    ts.load(names);
    return ts;
}

void TileSet::render(sf::RenderTarget &target, const sf::FloatRect &rect, const LevelTile &levelTile) {
    auto size = rect.getSize();
    auto width = size.x;
    auto height = size.y;

    sf::Sprite floor;
    floor.setTexture(getById(levelTile.floor_tile)->floor);
    floor.setPosition(rect.left, rect.top);
    floor.setScale(
            TILE_X_SIZE / floor.getLocalBounds().width,
            TILE_Y_SIZE / floor.getLocalBounds().height
    );
    target.draw(floor);

    if (!levelTile.pass_north) {
        sf::Sprite north;
        north.setTextureRect(sf::IntRect(0, 0, width, height / 10));
        north.setTexture(getById(levelTile.wall_tile)->wall);
        north.setPosition(rect.left, rect.top);
        target.draw(north);
    }

    if (!levelTile.pass_east) {
        sf::Sprite east;
        east.setTextureRect(sf::IntRect(0, 0, width / 10, height));
        east.setTexture(getById(levelTile.wall_tile)->wall);
        east.setPosition(rect.left + width - (width / 10.f), rect.top);
        target.draw(east);
    }

}