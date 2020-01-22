//
// Created by christian on 10.01.20.
//

#include "NPCSpec.h"

#include <utility>
#include "../YamlUtils.h"

NPCSpec NPCSpec::fromYAML(YAML::Node npcNode) {
    auto nameNode = npcNode["name"];
    auto maxHealthNode = npcNode["health"];

    auto name = nameNode.as<std::string>();
    auto pos = xyFromYAML(npcNode["position"]);
    auto maxHealth = maxHealthNode.as<int>();
    return NPCSpec(name, maxHealth, pos);
}

NPCSpec::NPCSpec(std::string name, int maxHealth, const sf::Vector2i &pos) : name(std::move(name)),
                                                                             maxHealth(maxHealth),
                                                                             pos(pos) {}
