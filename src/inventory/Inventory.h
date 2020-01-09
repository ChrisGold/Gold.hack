#pragma once

#include <string>
#include "../resources/Fonts.h"
#include "../resources/Resources.h"

class Inventory {
public:
    Inventory(std::string name);

    std::string name;

    void draw(sf::RenderTarget &target, Resources &resources);
};
