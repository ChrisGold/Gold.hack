//
// Created by y0079849 on 1/17/20.
//

#pragma once


#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "../resources/Resources.h"

class Item {
public:
    Item(std::string name, int attack, int range, int durability, int toughness,
         std::string icon);

private:
    std::string name;
    std::string icon;
public:
    [[nodiscard]] const std::string &getName() const;

    int attack;
    int range;
    int durability;
    int toughness;

    const sf::Texture &getTexture(const Resources &resources);

    const std::string &getIconTexture();
};


