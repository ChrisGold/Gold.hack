#pragma once

#include <vector>
#include <string>
#include <ostream>
#include <variant>
#include "Resources.h"
#include "../worldgen/static/LevelSpec.h"
#include "ResourceSpec.h"
#include "../level/Level.h"
#include "../worldgen/procedural/ProceduralLevelSpec.h"

class Config {
public:
    static Config loadFromYAML(const std::string &path);

    int getFontId(std::string fontName);

    int getTextureId(std::string textureName);

    Resources loadResources();

    std::vector<Level> generateLevels();

private:
    Config();

    void initFromFile(const std::string &path);

    std::vector<ResourceSpec> textures;
    std::vector<ResourceSpec> fonts;
    std::vector<std::variant<LevelSpec, ProceduralLevelSpec>> levelSpecs;

};
