#pragma once

#include <SFML/Graphics/Font.hpp>
#include "../level/LevelTile.h"

class Resources {
    std::vector<sf::Font *> fonts;
    std::vector<sf::Texture *> textures;

    void loadFont(const std::string &fontname);

    void loadTexture(const std::string &filename);

public:
    Resources();

    sf::Font * getFont(int font_id);

    sf::Texture * getTexture(int tile_id);

    static Resources init();

    void render(sf::RenderTarget &target, const sf::FloatRect &rect, int obj_id);

    void render(sf::RenderTarget &target, const sf::FloatRect &rect, const LevelTile &levelTile);
};
