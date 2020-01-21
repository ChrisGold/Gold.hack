#pragma once

#include <string>
#include "../resources/Resources.h"
#include "Item.h"

class Inventory {
    std::vector<Item> items;
    int selected_item;
public:
    Inventory(std::string name);

    std::string name;

    void draw(sf::RenderTarget &target, Resources &resources);

    int currentAttack();
};
