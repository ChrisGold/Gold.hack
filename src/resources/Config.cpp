//
// Created by christian on 09.01.20.
//

#include "Config.h"
#include "yaml-cpp/yaml.h"
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
        fs::path tex = resourcesFolder / textureFile.as<std::string>();
        textures.push_back(tex);
    }
    for (const auto &fontFile : resourceConfigYAML["fonts"]) {
        fs::path font = resourcesFolder / fontFile.as<std::string>();
        fonts.push_back(font);
    }
    for (const auto &levelNode : resourceConfigYAML["levels"]) {
        auto l = LevelSpec::fromYAML(levelNode);
        levelSpecs.push_back(l);
    }
}

Resources Config::loadResources() {
    Resources resources{};
    for (const fs::path texture : textures) {
        resources.loadTexture(texture.stem(), texture);
    }
    for (const fs::path font : fonts) {
        resources.loadFont(font.stem(), font);
    }
    return resources;
}
