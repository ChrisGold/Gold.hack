//
// Created by christian on 23.01.20.
//

#include "worldgen/static/NPCSpec.h"
#include "worldgen/static/LevelSpec.h"
#include "YamlUtils.h"

sf::Vector2i widthHeightFromYAML(YAML::Node coords) {
    int x = coords["width"].as<int>();
    int y = coords["height"].as<int>();
    return sf::Vector2i(x, y);
}

sf::Vector2i xyFromYAML(YAML::Node coords) {
    int x = coords["x"].as<int>();
    int y = coords["y"].as<int>();
    return sf::Vector2i(x, y);
}