//
// Created by christian on 10.01.20.
//

#include "LevelSpec.h"
#include "NPCSpec.h"
#include "../YamlUtils.h"

LevelSpec::LevelSpec() = default;

LevelSpec LevelSpec::fromYAML(const YAML::Node &levelNode) {
    auto ls = LevelSpec();
    for (const auto &roomNode : levelNode["rooms"]) {
        ls.rooms.push_back(RoomSpec::fromYAML(roomNode));
    }
    for (const auto &characterNode : levelNode["npcs"]) {
        ls.npcs.push_back(NPCSpec::fromYAML(characterNode));
    }
    ls.entry = xyFromYAML(levelNode["entry"]);
    ls.exit = xyFromYAML(levelNode["exit"]);
    return ls;
}

RoomSpec RoomSpec::fromYAML(YAML::Node roomNode) {
    RoomSpec rs;
    rs.floor = roomNode["floor"].as<std::string>();
    rs.wall = roomNode["wall"].as<std::string>();
    rs.position = xyFromYAML(roomNode["position"]);
    rs.size = widthHeightFromYAML(roomNode["size"]);
    return rs;
}
