#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureSet.h"
#include "../Constants.h"

std::shared_ptr<const sf::Texture> TextureSet::getById(int id) {
    return textures[0];
}

void TextureSet::load(std::string &file) {
    std::string path = file + ".png";
    std::cout << "Loading: " << path << std::endl;
    auto tex = std::make_shared<sf::Texture>();
    tex->loadFromFile(path);
    textures.push_back(tex);
}

void TextureSet::load(std::vector<std::string> &files) {
    for (std::string &file : files) load(file);
}

void TextureSet::render(sf::RenderTarget &target, const sf::FloatRect &rect, int obj_id) {
    sf::Sprite object;
    object.setTexture(*getById(obj_id));
    object.setPosition(rect.left, rect.top);
    object.setScale(
            TILE_X_SIZE / object.getLocalBounds().width,
            TILE_Y_SIZE / object.getLocalBounds().height
    );
    target.draw(object);
}

TextureSet TextureSet::init() {
    TextureSet ts;
    std::vector<std::string> files = {"player"};
    ts.load(files);
    return ts;
}
