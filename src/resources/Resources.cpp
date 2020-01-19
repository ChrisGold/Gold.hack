//
// Created by christian on 08.01.20.
//

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Resources.h"
#include "../Constants.h"
#include "../level/LevelTile.h"

Resources::Resources() : fonts(), textures() {

}

void Resources::loadFont(const std::string &fontname, const std::string &path) {
    std::cout << "Loading: " << path << std::endl;
    auto font = new sf::Font();
    font->loadFromFile(path);
    fonts.push_back(font);
}

void Resources::loadTexture(const std::string &texture, const std::string &path) {
    std::cout << "Loading: " << path << std::endl;
    auto tex = new sf::Texture();
    tex->loadFromFile(path);
    textures.push_back(tex);
}

sf::Font * Resources::getFont(int font_id) {
    return fonts[font_id];
}

sf::Texture * Resources::getTexture(int tile_id) {
    return textures[tile_id];;
}

void Resources::render(sf::RenderTarget &target, const sf::FloatRect &rect, int obj_id) {
    sf::Sprite object;
    object.setTexture(*getTexture(obj_id));
    object.setPosition(rect.left, rect.top);
    object.setScale(
            TILE_X_SIZE / object.getLocalBounds().width,
            TILE_Y_SIZE / object.getLocalBounds().height
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
/*
    if (!levelTile.pass_north) {
        sf::Sprite north;
        north.setTextureRect(sf::IntRect(0, 0, width, height / 10));
        north.setTexture(*getTexture(levelTile.wall_tile));
        north.setPosition(rect.left, rect.top);
        target.draw(north);
    }

    if (!levelTile.pass_east) {
        sf::Sprite east;
        east.setTextureRect(sf::IntRect(0, 0, width / 10, height));
        east.setTexture(*getTexture(levelTile.wall_tile));
        east.setPosition(rect.left + width - (width / 10.f), rect.top);
        target.draw(east);
    }

    if (!levelTile.pass_south) {
        sf::Sprite south;
        south.setTextureRect(sf::IntRect(0, 0, width, height / 10));
        south.setTexture(*getTexture(levelTile.wall_tile));
        south.setPosition(rect.left, rect.top + height - (height / 10.f));
        target.draw(south);
    }

    if (!levelTile.pass_west) {
        sf::Sprite west;
        west.setTextureRect(sf::IntRect(0, 0, width / 10, height));
        west.setTexture(*getTexture(levelTile.wall_tile));
        west.setPosition(rect.left, rect.top);
        target.draw(west);
    }
    */

}