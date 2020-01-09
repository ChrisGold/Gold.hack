#pragma once

#include <vector>
#include <string>
#include <ostream>
#include "Resources.h"

class ResourceConfig {
public:
    static ResourceConfig loadFromYAML(const std::string &path);

    Resources loadResources();

private:
    ResourceConfig();

    void initFromFile(const std::string &path);

    std::vector<std::string> textures;
    std::vector<std::string> fonts;
};
