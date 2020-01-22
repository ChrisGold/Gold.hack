//
// Created by christian on 08.01.20.
//

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Resources.h"
#include "../Constants.h"
#include "../level/LevelTile.h"

Resources::Resources() : fonts(), textures(), fontsByName(), texturesByName() {

}

void Resources::loadFont(const std::string &fontname, const std::string &path) {
    std::cout << "Loading: " << path << std::endl;
    auto font = new sf::Font();
    font->loadFromFile(path);
    fonts.push_back(font);
    fontsByName[fontname] = font;
}

void Resources::loadTexture(const std::string &texture, const std::string &path) {
    std::cout << "Loading: " << path << std::endl;
    auto tex = new sf::Texture();
    tex->loadFromFile(path);
    textures.push_back(tex);
    texturesByName[texture] = tex;
}

sf::Font *Resources::getFont(int font_id) const {
    return fonts[font_id];
}

sf::Texture *Resources::getTexture(int tile_id) const {
    return textures[tile_id];;
}

void Resources::render(sf::RenderTarget &target, const sf::FloatRect &rect, int obj_id) {
    auto size = rect.getSize();
    auto width = size.x;
    auto height = size.y;

    sf::Sprite object;
    object.setTexture(*getTexture(obj_id));
    object.setPosition(rect.left, rect.top);
    object.setScale(
            width / object.getLocalBounds().width,
            height / object.getLocalBounds().height
    );
    target.draw(object);
}

void Resources::render(sf::RenderTarget &target, const sf::FloatRect &rect, const LevelTile &levelTile) {
    auto size = rect.getSize();
    auto width = size.x;
    auto height = size.y;

    sf::Sprite floor;
    floor.setTexture(*getTexture(levelTile.floor_tile));
    floor.setPosition(rect.left, rect.top);
    floor.setScale(
            width / floor.getLocalBounds().width,
            height / floor.getLocalBounds().height
    );
    target.draw(floor);

    if (!levelTile.pass_north) {
        sf::Sprite north;
        auto tex = getTexture(levelTile.wall_tile);
        north.setTexture(*tex);
        north.setPosition(rect.left + (rect.width / 2), rect.top);
        auto oldRect = north.getTextureRect();
        north.setTextureRect(
                sf::IntRect(oldRect.left + (oldRect.width / 2), oldRect.top, oldRect.width / 2, oldRect.height));
        north.setScale(
                width / north.getLocalBounds().width / 2,
                height / north.getLocalBounds().height
        );
        target.draw(north);
    }

    if (!levelTile.pass_west) {
        sf::Sprite west;
        auto tex = getTexture(levelTile.wall_tile);
        west.setTexture(*tex);
        west.setPosition(rect.left, rect.top);
        auto oldRect = west.getTextureRect();
        oldRect.width = oldRect.width / 2;
        west.setTextureRect(oldRect);
        west.setScale(
                width / west.getLocalBounds().width / 2,
                height / west.getLocalBounds().height
        );
        target.draw(west);
    }

}

sf::Font *Resources::getFont(std::string name) const {
    return fontsByName.at(name);
}

sf::Texture *Resources::getTexture(std::string name) const {
    return texturesByName.at(name);
}
