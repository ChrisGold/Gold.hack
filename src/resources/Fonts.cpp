//
// Created by christian on 07.01.20.
//


#include <iostream>
#include "Fonts.h"
#include "../Constants.h"

void Fonts::load(std::vector<std::string> &files) {
    for (const auto &file : files) {
        load(file);
    }
}

void Fonts::load(const std::string &file) {
    std::string path = file + ".ttf";
    std::cout << "Loading: " << path << std::endl;
    auto font = sf::Font();
    font.loadFromFile(path);
    fonts[file] = font;
}

sf::Font &Fonts::getByName(const std::string &name) {
    return fonts[name];
}

Fonts Fonts::init() {
    Fonts fonts{};
    fonts.load(FONT_DEFAULT);
    return fonts;
}
