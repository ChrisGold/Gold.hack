//
// Created by christian on 28.01.20.
//

#include "ProceduralRoomSpec.h"
#include "../../YamlUtils.h"

ProceduralRoomSpec ProceduralRoomSpec::fromYAML(YAML::Node roomNode) {
    auto spec = ProceduralRoomSpec();
    spec.size = widthHeightFromYAML(roomNode["size"]);
    spec.floor = roomNode["floor"].as<std::string>();
    return spec;
}
