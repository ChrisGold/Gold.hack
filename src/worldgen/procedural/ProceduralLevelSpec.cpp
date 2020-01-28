//
// Created by christian on 28.01.20.
//

#include <iostream>
#include "yaml-cpp/yaml.h"
#include "ProceduralLevelSpec.h"

ProceduralLevelSpec ProceduralLevelSpec::fromYAML(YAML::Node levelNode) {
    auto spec = ProceduralLevelSpec();
    for (const auto &node : levelNode) {
        std::cout << node.first << ": " << node.second << std::endl;
    }
    spec.floor = levelNode["floor"].as<std::string>();
    spec.exit_tile = levelNode["exit"].as<std::string>();

    for (const auto &roomNode : levelNode["rooms"]) {
        spec.rooms.push_back(ProceduralRoomSpec::fromYAML(roomNode));
    }

    for (const auto &npcNode : levelNode["npcs"]) {
        spec.npcs.push_back(ProceduralNPCSpec::fromYAML(npcNode));
    }

    return spec;
}
