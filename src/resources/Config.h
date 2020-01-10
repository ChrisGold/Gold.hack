#pragma once

#include <vector>
#include <string>
#include <ostream>
#include "Resources.h"
#include "../worldgen/LevelSpec.h"
#include "ResourceSpec.h"

class Config {
public:
    static Config loadFromYAML(const std::string &path);

    Resources loadResources();

private:
    Config();

    void initFromFile(const std::string &path);

    std::vector<ResourceSpec> textures;
    std::vector<ResourceSpec> fonts;
    std::vector<LevelSpec> levelSpecs;
};
