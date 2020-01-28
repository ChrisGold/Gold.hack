//
// Created by christian on 28.01.20.
//

#include "ProceduralNPCSpec.h"

ProceduralNPCSpec ProceduralNPCSpec::fromYAML(YAML::Node npcNode) {
    auto spec = ProceduralNPCSpec();
    spec.name = npcNode["name"].as<std::string>();
    spec.maxHealth = npcNode["health"].as<int>();
    spec.texture = npcNode["texture"].as<std::string>();
    return spec;
}
