//
// Created by christian on 28.01.20.
//

#pragma once

#include <string>
#include "ProceduralRoomSpec.h"
#include "ProceduralNPCSpec.h"

struct ProceduralLevelSpec {
    std::string floor;
    std::string exit_tile;
    std::vector<ProceduralRoomSpec> rooms;
    std::vector<ProceduralNPCSpec> npcs;

    static ProceduralLevelSpec fromYAML(YAML::Node levelNode);
};


