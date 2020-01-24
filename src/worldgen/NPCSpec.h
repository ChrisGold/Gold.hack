#pragma once

#include <yaml-cpp/node/node.h>
#include <SFML/System.hpp>

struct NPCSpec {
    std::string name;
    std::string type;

    NPCSpec(std::string name, std::string type, int maxHealth, const sf::Vector2i &pos);

    int maxHealth;
    sf::Vector2i pos;

    static NPCSpec fromYAML(YAML::Node npcNode);
};
