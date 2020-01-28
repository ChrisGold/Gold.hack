//
// Created by christian on 28.01.20.
//

#pragma once


#include <string>
#include <yaml-cpp/yaml.h>

struct ProceduralNPCSpec {
    std::string name;
    std::string texture;
    int maxHealth;

    static ProceduralNPCSpec fromYAML(YAML::Node npcNode);
};


