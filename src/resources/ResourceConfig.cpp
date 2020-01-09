//
// Created by christian on 09.01.20.
//

#include "ResourceConfig.h"
#include "yaml-cpp/yaml.h"
#include <experimental/filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;

ResourceConfig::ResourceConfig()
        : textures(), fonts() {}

ResourceConfig ResourceConfig::loadFromYAML(const std::string &path) {
    ResourceConfig res = ResourceConfig();
    res.initFromFile(path);
    return res;
}

void ResourceConfig::initFromFile(const std::string &path) {
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
}

Resources ResourceConfig::loadResources() {
    Resources resources{};
    for (const fs::path texture : textures) {
        resources.loadTexture(texture.stem(), texture);
    }
    for (const fs::path font : fonts) {
        resources.loadFont(font.stem(), font);
    }
    return resources;
}
