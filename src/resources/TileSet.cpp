#include <iostream>
#include "TileSet.h"
#include "../Constants.h"

std::shared_ptr<const Tile> TileSet::getById(int id) {
    return tiles[id];
}

void TileSet::load(std::string &file){
    std::string path = file + ".png";
    std::cout << "Loading: " << path << std::endl;
    sf::Texture tex;
    tex.loadFromFile(path);
    int id = tiles.size();
    auto ptr = std::make_shared<Tile>(tex, file, id);
    tiles.push_back(ptr);
}

void TileSet::load(std::vector<std::string> &files){
    for(std::string &file : files) load(file);
}

TileSet TileSet::init(){
    TileSet ts{};
    std::vector<std::string> names = {"void", "wood", "stone"};
    ts.load(names);
    return ts;
}

sf::Sprite TileSet::make_sprite(int id){
    sf::Sprite sprite;
    auto tile = getById(id);
    sprite.setTexture(tile->texture);

    sprite.setScale(
        TILE_X_SIZE / sprite.getLocalBounds().width, 
        TILE_Y_SIZE / sprite.getLocalBounds().height
    );
    return sprite;
}