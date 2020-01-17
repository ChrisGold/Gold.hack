#pragma once

#include <string>
#include "../resources/Resources.h"
#include "Item.h"

class Inventory {
    std::vector<Item> items;
public:
    Inventory(std::string name);

    std::string name;

    void draw(sf::RenderTarget &target, Resources &resources);
};
