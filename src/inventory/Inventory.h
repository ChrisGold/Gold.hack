#pragma once

#include <string>
#include "../resources/Resources.h"
#include "Item.h"

class Game;

class Inventory {
    std::vector<Item> items;
    int selected_item;
public:
    Inventory(std::string name);

    std::string name;

    void draw(sf::RenderTarget &target, Resources &resources, Game *game);

    int currentAttack();

    Item &currentItem();

    void scrollLeft();

    void scrollRight();
};
