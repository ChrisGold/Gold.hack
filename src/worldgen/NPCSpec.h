#pragma once

#include <yaml-cpp/node/node.h>

struct NPCSpec {
    static NPCSpec fromYAML(YAML::Node npcNode);
};
