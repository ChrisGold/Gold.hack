//
// Created by christian on 09.01.20.
//

#include "Config.h"
#include "yaml-cpp/yaml.h"
#include "../level/Level.h"
#include "../worldgen/LevelGenerator.h"
#include "../worldgen/static/StaticLevelGenerator.h"
#include "../worldgen/procedural/ProceduralLevelGenerator.h"
#include <experimental/filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;

Config::Config()
        : textures(), fonts() {}

Config Config::loadFromYAML(const std::string &path) {
    Config res = Config();
    res.initFromFile(path);
    return res;
}

void Config::initFromFile(const std::string &path) {
    YAML::Node resourceConfigYAML = YAML::LoadFile(path);
    fs::path resourcesFolder(resourceConfigYAML["prefix"].as<std::string>());
    for (const auto &textureFile : resourceConfigYAML["textures"]) {
        fs::path file = textureFile.as<std::string>();
        fs::path filepath = resourcesFolder / file;
        textures.emplace_back(file.stem(), filepath);
    }
    for (const auto &fontFile : resourceConfigYAML["fonts"]) {
        fs::path file = fontFile.as<std::string>();
        fs::path filepath = resourcesFolder / file;
        fonts.emplace_back(file.stem(), filepath);
    }
    for (const auto &levelNode : resourceConfigYAML["levels"]) {
        auto type = levelNode["type"].as<std::string>();
        if (type == "static") {
            auto l = LevelSpec::fromYAML(levelNode);
            levelSpecs.emplace_back(l);
        } else if (type == "gen") {
            auto l = ProceduralLevelSpec::fromYAML(levelNode);
            levelSpecs.emplace_back(l);
        }
    }
}

Resources Config::loadResources() {
    Resources resources{};
    for (auto texSpec : textures) {
        const fs::path texture = texSpec.path;
        resources.loadTexture(texture.stem(), texture);
    }
    for (auto fontSpec : fonts) {
        const fs::path spec = fontSpec.path;
        resources.loadFont(spec.stem(), spec);
    }
    return resources;
}

std::vector<Level> Config::generateLevels() {
    std::vector<Level> levels;

    StaticLevelGenerator lg;
    ProceduralLevelGenerator plg;

    for (auto levelSpec: levelSpecs) {
        if (std::holds_alternative<LevelSpec>(levelSpec)) {
            lg.generate(std::get<LevelSpec>(levelSpec), *this);
            levels.push_back(lg.export_level());
            lg.reset();
        } else {
            plg.generate(std::get<ProceduralLevelSpec>(levelSpec));
            levels.push_back(plg.export_level());
            plg.reset();
        }
    }
    return levels;
}

int Config::getFontId(std::string fontName) {
    auto it = std::find_if(fonts.begin(), fonts.end(), [fontName](ResourceSpec rs) { return rs.name == fontName; });
    return std::distance(fonts.begin(), it);
}

int Config::getTextureId(std::string textureName) {
    auto it = std::find_if(textures.begin(), textures.end(),
                           [textureName](ResourceSpec rs) { return rs.name == textureName; });
    return std::distance(textures.begin(), it);
}
