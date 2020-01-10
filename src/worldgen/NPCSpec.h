#pragma once

#include <yaml-cpp/node/node.h>

class NPCSpec {
public:
    static NPCSpec fromYAML(YAML::Node npcNode);
};
