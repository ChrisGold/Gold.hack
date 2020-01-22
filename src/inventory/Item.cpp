//
// Created by y0079849 on 1/17/20.
//

#include "Item.h"
#include "../resources/Resources.h"

#include <utility>
#include <SFML/Graphics/Texture.hpp>

Item::Item(std::string name, int attack, int range, int durability, int toughness,
           std::string icon) : name(std::move(name)), attack(attack),
                               range(range),
                               durability(durability),
                               toughness(toughness),
                               icon(std::move(icon)) {}

const std::string &Item::getName() const {
    return name;
}

const sf::Texture &Item::getTexture(const Resources &resources) {
    return *resources.getTexture(this->icon);
}
