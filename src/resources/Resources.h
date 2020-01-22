#pragma once

#include <SFML/Graphics/Font.hpp>
#include "../level/LevelTile.h"

class Resources {
    std::vector<sf::Font *> fonts;
    std::vector<sf::Texture *> textures;
    std::map<std::string, sf::Font *> fontsByName;
    std::map<std::string, sf::Texture *> texturesByName;

public:

    Resources();

    sf::Font *getFont(int font_id) const;

    sf::Font *getFont(std::string name) const;

    sf::Texture *getTexture(int tile_id) const;

    sf::Texture *getTexture(std::string name) const;

    void loadTexture(const std::string &texture, const std::string &path);

    void loadFont(const std::string &fontname, const std::string &path);

    void render(sf::RenderTarget &target, const sf::FloatRect &rect, int obj_id);

    void render(sf::RenderTarget &target, const sf::FloatRect &rect, const LevelTile &levelTile);
};
