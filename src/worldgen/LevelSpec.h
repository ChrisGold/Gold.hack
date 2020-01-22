#pragma once

#include <string>
#include <SFML/System/Vector2.hpp>
#include "yaml-cpp/yaml.h"
#include "NPCSpec.h"

struct RoomSpec {
    sf::Vector2i position;
    sf::Vector2i size;
    std::string floor;
    std::string wall;

    static RoomSpec fromYAML(YAML::Node roomNode);
};

struct LevelSpec {
    sf::Vector2i entry;
    sf::Vector2i exit;
    std::vector<RoomSpec> rooms;
    std::vector<NPCSpec> npcs;

    static LevelSpec fromYAML(const YAML::Node &levelNode);

private:
    LevelSpec();
};

