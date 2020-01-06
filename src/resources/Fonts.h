#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics/Font.hpp>

class Fonts {
    std::map<std::string, sf::Font> fonts;
public:
    void load(std::vector<std::string> &files);

    sf::Font &getByName(const std::string &name);

    static Fonts init();

    void load(const std::string &file);
};
