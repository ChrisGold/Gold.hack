#pragma once

#include <vector>
#include <string>
#include <ostream>
#include "Resources.h"
#include "../worldgen/LevelSpec.h"

class Config {
public:
    static Config loadFromYAML(const std::string &path);

    Resources loadResources();

private:
    Config();

    void initFromFile(const std::string &path);

    std::vector<std::string> textures;
    std::vector<std::string> fonts;
    std::vector<LevelSpec> levelSpecs;
};
