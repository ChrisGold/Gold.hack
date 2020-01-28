//
// Created by christian on 28.01.20.
//

#pragma once


#include <yaml-cpp/node/node.h>
#include <SFML/System/Vector2.hpp>

struct ProceduralRoomSpec {
    sf::Vector2i size;
    std::string floor;

    static ProceduralRoomSpec fromYAML(YAML::Node roomNode);
};


