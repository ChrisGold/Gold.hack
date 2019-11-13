#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>
#include "TileSet.h"
#include "../Constants.h"

std::shared_ptr<const Tile> TileSet::getById(int id) {
    return tiles[id];
}

void TileSet::load(std::string &file) {
    std::string path = file + ".png";
    std::cout << "Loading: " << path << std::endl;
    sf::Texture tex;
    tex.loadFromFile(path);
    int id = tiles.size();
    auto ptr = std::make_shared<Tile>(tex, file, id);
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

void TileSet::render(sf::RenderTarget &target, const LevelTile &levelTile) {
    sf::Sprite north;
    sf::Sprite east;
    sf::Sprite floor;

    auto size = target.getSize();
    auto width = size.x;
    auto height = size.y;

    north.setTextureRect(sf::IntRect(0, 0, width, height / 10));
    north.setTexture(getById(2)->texture);
    north.setPosition(0, 0);

    east.setTextureRect(sf::IntRect(0, 0, width / 10, height));
    east.setTexture(getById(1)->texture);
    east.setPosition(width - (width / 10.f), 0);

    floor.setTexture(getById(levelTile.tile_id)->texture);
    floor.setPosition(0.0f, 0.0f);
    floor.setScale(
            TILE_X_SIZE / floor.getLocalBounds().width,
            TILE_Y_SIZE / floor.getLocalBounds().height
    );

    target.draw(floor);
    target.draw(north);
    target.draw(east);

}