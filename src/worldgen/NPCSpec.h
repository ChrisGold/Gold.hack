#pragma once

#include <yaml-cpp/node/node.h>
#include <SFML/System.hpp>

struct NPCSpec {
    std::string name;

    NPCSpec(std::string name, int maxHealth, const sf::Vector2i &pos);

    int maxHealth;
    sf::Vector2i pos;

    static NPCSpec fromYAML(YAML::Node npcNode);
};
